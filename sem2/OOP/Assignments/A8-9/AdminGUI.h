#pragma once
#include <QtWidgets/Qwidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QDialog>
#include <QtWidgets/QComboBox>
#include "AdminService.h"

class AdminGUI : public QDialog {
    Q_OBJECT
private:
    std::shared_ptr<Admin_Service> admin_service;
    QPushButton* addButton;
    QPushButton* removeButton;
    QPushButton* updateButton;
    QPushButton* showAllButton;
    QPushButton* extraButton;
    QComboBox* modeComboBox;
    QPushButton Undo;
    QPushButton Redo;

public:
    AdminGUI(std::shared_ptr<Admin_Service> adminService, QWidget* parent = nullptr);

private slots:
    void generate_10_movies();
    void handleAdd();
    void handleRemove();
    void handleUpdate();
    void handleShowAll();
    void handleExtraRequirement();
    void handleComboBoxChange(const QString& mode);
    void handleUndo();
    void handleRedo();
};

