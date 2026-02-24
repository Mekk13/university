#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include "Movie.h"
#include "AdminService.h"
#include "UserService.h"
#include <string>
#include <cstdlib>
#include "Validator.h"
#include "FileRepo.h"

class A89 : public QMainWindow
{
    Q_OBJECT

public:
    A89(QWidget* parent = nullptr);
    ~A89();

private slots:
    void handleInitialMemoryMode();
    void handleInitialFileMode();
    void handleModeSelection(Repo& r);
    void openAdminMode(Repo& r);
    void openUserMode(Repo& r,QString format);
    void populate(Admin_Service& a, User_Service& u);

private:
    Watch_Repository* watchRepo;
    QPushButton* memoryButton;
    QPushButton* fileButton;
};
