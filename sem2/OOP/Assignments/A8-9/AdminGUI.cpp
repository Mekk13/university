#include "AdminGUI.h"
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTextEdit>
#include <QShortcut>
#include <QKeySequence>

AdminGUI::AdminGUI(std::shared_ptr<Admin_Service> adminService, QWidget* parent)
    : QDialog(parent), admin_service(adminService)
{
    setWindowTitle("Admin Mode");
    setMinimumSize(400, 300);

    
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Action buttons
    QPushButton* addButton = new QPushButton("Add Movie", this);
    QPushButton* removeButton = new QPushButton("Remove Movie", this);
    QPushButton* updateButton = new QPushButton("Update Movie", this);
    QPushButton* displayButton = new QPushButton("Display All Movies", this);
    QPushButton* Undo = new QPushButton("Undo", this);
    QPushButton* Redo = new QPushButton("Redo", this);
    extraButton = new QPushButton("Extra Requirement", this);

    mainLayout->addWidget(addButton);
    mainLayout->addWidget(removeButton);
    mainLayout->addWidget(updateButton);
    mainLayout->addWidget(displayButton);
    mainLayout->addWidget(extraButton);
    mainLayout->addWidget(Undo);
    mainLayout->addWidget(Redo);

    //  combo box 
    modeComboBox = new QComboBox(this);
    modeComboBox->addItem("Short Mode");
    modeComboBox->addItem("Long Mode");
    modeComboBox->hide();
    mainLayout->addWidget(modeComboBox);

    // Connect 
    connect(addButton, &QPushButton::clicked, this, &AdminGUI::handleAdd);
    connect(removeButton, &QPushButton::clicked, this, &AdminGUI::handleRemove);
    connect(updateButton, &QPushButton::clicked, this, &AdminGUI::handleUpdate);
    connect(displayButton, &QPushButton::clicked, this, &AdminGUI::handleShowAll);
    connect(extraButton, &QPushButton::clicked, this, &AdminGUI::handleExtraRequirement);
    connect(modeComboBox, &QComboBox::currentTextChanged, this, &AdminGUI::handleComboBoxChange);
	connect(Undo, &QPushButton::clicked, this, &AdminGUI::handleUndo);
	connect(Redo, &QPushButton::clicked, this, &AdminGUI::handleRedo);

    QShortcut* undoShortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
    QShortcut* redoShortcut = new QShortcut(QKeySequence("Ctrl+Y"), this);

    // Connect shortcuts to slots/functions
    connect(undoShortcut, &QShortcut::activated, this, &AdminGUI::handleUndo);
    connect(redoShortcut, &QShortcut::activated, this, &AdminGUI::handleRedo);
	
}



void AdminGUI::generate_10_movies()
{
    // Add default movies to the repo
    this->admin_service->add_movie("The Devil Wears Prada", "Drama", "https://tinyurl.com/4f4skkbb", "2006", "100");
    this->admin_service->add_movie("Inception", "Sci-Fi", "https://www.youtube.com/watch?v=YoHD9XEInc0", "2010", "950");
    this->admin_service->add_movie("The Grand Budapest Hotel", "Comedy", "https://www.youtube.com/watch?v=1Fg5iWmQjwk", "2014", "720");
    this->admin_service->add_movie("Parasite", "Thriller", "https://www.youtube.com/watch?v=5xH0HfJHsaY", "2019", "860");
    this->admin_service->add_movie("La La Land", "Musical", "https://www.youtube.com/watch?v=0pdqf4P9MB8", "2016", "780");
    this->admin_service->add_movie("Interstellar", "Sci-Fi", "https://www.youtube.com/watch?v=zSWdZVtXT7E", "2014", "980");
    this->admin_service->add_movie("Whiplash", "Drama", "https://www.youtube.com/watch?v=7d_jQycdQGo", "2014", "640");
    this->admin_service->add_movie("The Social Network", "Biography", "https://www.youtube.com/watch?v=lB95KLmpLR4", "2010", "690");
    this->admin_service->add_movie("Joker", "Crime", "https://www.youtube.com/watch?v=zAGVQLHvwOY", "2019", "820");
    this->admin_service->add_movie("Pulp Fiction", "Crime", "https://www.youtube.com/watch?v=s7EdQ4FqbhY", "1994", "900");

    //
    this->admin_service->add_movie("The Devil Wears Prada1", "Drama", "https://tinyurl.com/4f4skkbb", "2006", "100");
    this->admin_service->add_movie("Inception1", "Sci-Fi", "https://www.youtube.com/watch?v=YoHD9XEInc0", "2010", "950");
    this->admin_service->add_movie("The Grand Budapest Hotel1", "Comedy", "https://www.youtube.com/watch?v=1Fg5iWmQjwk", "2014", "720");
    this->admin_service->add_movie("Parasit1e", "Thriller", "https://www.youtube.com/watch?v=5xH0HfJHsaY", "2019", "860");
    this->admin_service->add_movie("La La La1nd", "Musical", "https://www.youtube.com/watch?v=0pdqf4P9MB8", "2016", "780");
    this->admin_service->add_movie("Interstel1lar", "Sci-Fi", "https://www.youtube.com/watch?v=zSWdZVtXT7E", "2014", "980");
    this->admin_service->add_movie("Whiplas1h", "Drama", "https://www.youtube.com/watch?v=7d_jQycdQGo", "2014", "640");
    this->admin_service->add_movie("The Soc1ial Network", "Biography", "https://www.youtube.com/watch?v=lB95KLmpLR4", "2010", "690");
    this->admin_service->add_movie("Joke1r", "Crime", "https://www.youtube.com/watch?v=zAGVQLHvwOY", "2019", "820");
    this->admin_service->add_movie("Pulp 1Fiction", "Crime", "https://www.youtube.com/watch?v=s7EdQ4FqbhY", "1994", "900");
}

void AdminGUI::handleAdd()
{
    QDialog* addDialog = new QDialog(this);
    QVBoxLayout* dialogLayout = new QVBoxLayout(addDialog);

    QLineEdit* titleEdit = new QLineEdit(addDialog);
    titleEdit->setPlaceholderText("Enter Movie Title");
    dialogLayout->addWidget(titleEdit);

    QLineEdit* genreEdit = new QLineEdit(addDialog);
    genreEdit->setPlaceholderText("Enter Movie Genre");
    dialogLayout->addWidget(genreEdit);

    QLineEdit* trailerEdit = new QLineEdit(addDialog);
    trailerEdit->setPlaceholderText("Enter Trailer Link");
    dialogLayout->addWidget(trailerEdit);

    QLineEdit* yearEdit = new QLineEdit(addDialog);
    yearEdit->setPlaceholderText("Enter Release Year");
    dialogLayout->addWidget(yearEdit);

    QLineEdit* likesEdit = new QLineEdit(addDialog);
    likesEdit->setPlaceholderText("Enter Number of Likes");
    dialogLayout->addWidget(likesEdit);

    QDialogButtonBox* buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, addDialog);
    dialogLayout->addWidget(buttons);

    connect(buttons, &QDialogButtonBox::accepted, this, [=]() {
        QString title = titleEdit->text();
        QString genre = genreEdit->text();
        QString trailer = trailerEdit->text();
        QString year = yearEdit->text();
        QString likes = likesEdit->text();

        if (admin_service->add_movie(title.toStdString(), genre.toStdString(), trailer.toStdString(), year.toStdString(), likes.toStdString())) {
            QMessageBox::information(this, "Success", "Movie added successfully!");
        }
        else {
            QMessageBox::warning(this, "Error", "A movie with that title and genre already exists!");
        }
        addDialog->accept();
        });

    connect(buttons, &QDialogButtonBox::rejected, addDialog, &QDialog::reject);

    addDialog->exec();
}



void AdminGUI::handleRemove()
{
    QDialog* removeDialog = new QDialog(this);
    QVBoxLayout* dialogLayout = new QVBoxLayout(removeDialog);

    QLineEdit* titleEdit = new QLineEdit(removeDialog);
    titleEdit->setPlaceholderText("Enter Movie Title");
    dialogLayout->addWidget(titleEdit);

    QLineEdit* genreEdit = new QLineEdit(removeDialog);
    genreEdit->setPlaceholderText("Enter Movie Genre");
    dialogLayout->addWidget(genreEdit);

    QDialogButtonBox* buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, removeDialog);
    dialogLayout->addWidget(buttons);

    connect(buttons, &QDialogButtonBox::accepted, this, [=]() {
        QString title = titleEdit->text();
        QString genre = genreEdit->text();

        if (admin_service->remove_movie(title.toStdString(), genre.toStdString())) {
            QMessageBox::information(this, "Success", "Movie removed successfully!");
        }
        else {
            QMessageBox::warning(this, "Error", "Movie with this title and genre not found.");
        }
        removeDialog->accept();
        });

    connect(buttons, &QDialogButtonBox::rejected, removeDialog, &QDialog::reject);

    removeDialog->exec();
}
void AdminGUI::handleUpdate()
{
    QDialog* updateDialog = new QDialog(this);
    QVBoxLayout* dialogLayout = new QVBoxLayout(updateDialog);

    QLineEdit* titleEdit = new QLineEdit(updateDialog);
    titleEdit->setPlaceholderText("Enter Movie Title to Update");
    dialogLayout->addWidget(titleEdit);

    QLineEdit* genreEdit = new QLineEdit(updateDialog);
    genreEdit->setPlaceholderText("Enter Movie Genre to Update");
    dialogLayout->addWidget(genreEdit);

    QLineEdit* newTitleEdit = new QLineEdit(updateDialog);
    newTitleEdit->setPlaceholderText("New Movie Title");
    dialogLayout->addWidget(newTitleEdit);

    QLineEdit* newGenreEdit = new QLineEdit(updateDialog);
    newGenreEdit->setPlaceholderText("New Movie Genre");
    dialogLayout->addWidget(newGenreEdit);

    QLineEdit* newTrailerEdit = new QLineEdit(updateDialog);
    newTrailerEdit->setPlaceholderText("New Trailer Link");
    dialogLayout->addWidget(newTrailerEdit);

    QLineEdit* newYearEdit = new QLineEdit(updateDialog);
    newYearEdit->setPlaceholderText("New Release Year");
    dialogLayout->addWidget(newYearEdit);

    QLineEdit* newLikesEdit = new QLineEdit(updateDialog);
    newLikesEdit->setPlaceholderText("New Likes");
    dialogLayout->addWidget(newLikesEdit);

    QDialogButtonBox* buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, updateDialog);
    dialogLayout->addWidget(buttons);

    connect(buttons, &QDialogButtonBox::accepted, this, [=]() {
        QString title = titleEdit->text();
        QString genre = genreEdit->text();
        QString newTitle = newTitleEdit->text();
        QString newGenre = newGenreEdit->text();
        QString newTrailer = newTrailerEdit->text();
        QString newYear = newYearEdit->text();
        QString newLikes = newLikesEdit->text();

        if (admin_service->update_movie(title.toStdString(), genre.toStdString(),
            newTitle.toStdString(), newGenre.toStdString(),
            newTrailer.toStdString(), newLikes.toStdString(), newYear.toStdString())) {
            QMessageBox::information(this, "Success", "Movie updated successfully!");
        }
        else {
            QMessageBox::warning(this, "Error", "Movie with the given title and genre not found.");
        }
        updateDialog->accept();
        });

    connect(buttons, &QDialogButtonBox::rejected, updateDialog, &QDialog::reject);

    updateDialog->exec();
}

void AdminGUI::handleShowAll()
{
    std::vector<Movie> allMovies = admin_service->get_all_movies();
    if (allMovies.empty()) {
        QMessageBox::information(this, "No Movies", "No movies available in the database.");
        return;
    }

    // scrollable text box
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Movies List");
    dialog->resize(600, 400); 

    QVBoxLayout* layout = new QVBoxLayout(dialog);

    QTextEdit* textEdit = new QTextEdit(dialog);
    textEdit->setReadOnly(true);

    QString allMoviesText;
    for (const auto& movie : allMovies) {
        allMoviesText += QString("Title: %1\nGenre: %2\nYear: %3\nLikes: %4\nTrailer: %5\n\n")
            .arg(QString::fromStdString(movie.getTitle()))
            .arg(QString::fromStdString(movie.getGenre()))
            .arg(QString::number(movie.getYear()))
            .arg(QString::number(movie.getLikes()))
            .arg(QString::fromStdString(movie.getTrailer()));
    }

    textEdit->setText(allMoviesText);
    layout->addWidget(textEdit);

    dialog->setLayout(layout);
    dialog->exec();  
}

void AdminGUI::handleExtraRequirement()
{
   
    QDialog* comboDialog = new QDialog(this);
    comboDialog->setWindowTitle("Select Mode");
    comboDialog->setMinimumSize(200, 150);

    QVBoxLayout* layout = new QVBoxLayout(comboDialog);
    layout->addWidget(new QLabel("Choose a Mode:", comboDialog));
    layout->addWidget(modeComboBox);

    modeComboBox->show();  
    comboDialog->exec(); 
}

void AdminGUI::handleComboBoxChange(const QString& mode)
{
    std::vector<Movie> allMovies = admin_service->get_all_movies();

    if (allMovies.empty()) {
        QMessageBox::information(this, "No Movies", "No movies available in the database.");
        return;
    }

    QString movieDetails;
    if (mode == "Short Mode") {
        for (const auto& movie : allMovies) {
            movieDetails += QString("Title: %1 | Genre: %2\n")
                .arg(QString::fromStdString(movie.getTitle()))
                .arg(QString::fromStdString(movie.getGenre()));
        }
    }
    else if (mode == "Long Mode") {
        for (const auto& movie : allMovies) {
            movieDetails += QString("Title: %1\nGenre: %2\nYear: %3\nLikes: %4\nTrailer: %5\n\n")
                .arg(QString::fromStdString(movie.getTitle()))
                .arg(QString::fromStdString(movie.getGenre()))
                .arg(QString::number(movie.getYear()))
                .arg(QString::number(movie.getLikes()))
                .arg(QString::fromStdString(movie.getTrailer()));
        }
    }

    QDialog* movieDialog = new QDialog(this);
    movieDialog->setWindowTitle(mode);
    movieDialog->resize(600, 400);

    QVBoxLayout* layout = new QVBoxLayout(movieDialog);
    QTextEdit* textEdit = new QTextEdit(movieDialog);
    textEdit->setReadOnly(true);
    textEdit->setText(movieDetails);
    layout->addWidget(textEdit);

    movieDialog->exec();
}


void AdminGUI::handleUndo()
{
    try {
        this->admin_service->undo();
		QMessageBox::information(this, "Undo Success", "Last action undone successfully!");
    }
    catch (std::exception& e) {
        QMessageBox::warning(this, "Undo Error", QString::fromStdString(e.what()));
    }

}

void AdminGUI::handleRedo()
{
	try {
		this->admin_service->redo();
		QMessageBox::information(this, "Redo Success", "Last action redone successfully!");
	}
	catch (std::exception& e) {
		QMessageBox::warning(this, "Redo Error", QString::fromStdString(e.what()));
	}
}
