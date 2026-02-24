#include "A89.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QComboBox>
#include "FileRepo.h"
#include "Repo.h"
#include "AdminService.h"
#include "AdminGUI.h"
#include "UserGUI.h"
#include "SelectFileForm.h"

A89::A89(QWidget* parent) : QMainWindow(parent), watchRepo(new Watch_Repository())
{
    setWindowTitle("Movie Management App");
    setMinimumSize(300, 200);

    // Buttons for initial mode selection (Memory or File)
    memoryButton = new QPushButton("Memory Mode", this);
    fileButton = new QPushButton("File Mode", this);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(memoryButton);
    layout->addWidget(fileButton);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Connecting buttons to their respective handlers
    connect(memoryButton, &QPushButton::clicked, this, &A89::handleInitialMemoryMode);
    connect(fileButton, &QPushButton::clicked, this, &A89::handleInitialFileMode);

}

A89::~A89()
{
    delete watchRepo;
}

void A89::handleInitialMemoryMode()
{
   
    Repo* r = new Repo;
    Admin_Service* adminService = new Admin_Service(*r);
    User_Service* userService = new User_Service(*r, *this->watchRepo);
    populate(*adminService, *userService);
    handleModeSelection(*r);
}

void A89::handleInitialFileMode()
{
    
    Repo* r = new FileRepo("movies.txt");
    Admin_Service* adminService = new Admin_Service(*r);
    User_Service* userService = new User_Service(*r, *this->watchRepo);  
    handleModeSelection(*r);
}


void A89::handleModeSelection(Repo& r)
{
    
    QMessageBox msgBox;
    msgBox.setWindowTitle("Choose Mode");
    msgBox.setText("Select Admin Mode or User Mode:");
    msgBox.setInformativeText("Admin Mode: Manage Movies\nUser Mode: Use your watchlist");

    QPushButton* adminButton = msgBox.addButton("Admin Mode", QMessageBox::AcceptRole);
    QPushButton* userButton = msgBox.addButton("User Mode", QMessageBox::RejectRole);

    msgBox.exec();

    // Handle user choice
    if (msgBox.clickedButton() == adminButton) {
        openAdminMode(r);
    }
    else if (msgBox.clickedButton() == userButton) {
        SelectFileForm fileform;
        fileform.exec();
        QString format = fileform.getselectedformat();
        if (format.isEmpty()) {
            QMessageBox::warning(this, "Error", "Please select a format");
        }
        else
            openUserMode(r,format);
    }
}

// Open Admin Mode
void A89::openAdminMode(Repo& r)
{
    AdminGUI* adminGui = new AdminGUI(std::make_shared<Admin_Service>(r));
    adminGui->setAttribute(Qt::WA_DeleteOnClose);
    adminGui->show();
}

// Open User Mode
void A89::openUserMode(Repo& r,QString format)
{
    std::shared_ptr<User_Service> user_serv = std::make_shared < User_Service>(r, *watchRepo);
    std::string stringformat = format.trimmed().toStdString();
    user_serv->set_file(stringformat);
    UserGUI* userGui = new UserGUI(user_serv);
    userGui->setAttribute(Qt::WA_DeleteOnClose);
    userGui->show();
}

void A89::populate(Admin_Service &a, User_Service &u)
{
    if (a.get_all_movies().empty()) {
        a.add_movie("The Devil Wears Prada", "Drama", "https://tinyurl.com/4f4skkbb", "2006", "100");
        a.add_movie("Inception", "Sci-Fi", "https://www.youtube.com/watch?v=YoHD9XEInc0", "2010", "950");
        a.add_movie("The Grand Budapest Hotel", "Comedy", "https://www.youtube.com/watch?v=1Fg5iWmQjwk", "2014", "720");
        a.add_movie("Parasite", "Thriller", "https://www.youtube.com/watch?v=5xH0HfJHsaY", "2019", "860");
        a.add_movie("La La Land", "Musical", "https://www.youtube.com/watch?v=0pdqf4P9MB8", "2016", "780");
        a.add_movie("Interstellar", "Sci-Fi", "https://www.youtube.com/watch?v=zSWdZVtXT7E", "2014", "980");
        a.add_movie("Whiplash", "Drama", "https://www.youtube.com/watch?v=7d_jQycdQGo", "2014", "640");
        a.add_movie("The Social Network", "Biography", "https://www.youtube.com/watch?v=lB95KLmpLR4", "2010", "690");
        a.add_movie("Joker", "Crime", "https://www.youtube.com/watch?v=zAGVQLHvwOY", "2019", "820");
        a.add_movie("Pulp Fiction", "Crime", "https://www.youtube.com/watch?v=s7EdQ4FqbhY", "1994", "900");
    }
}

