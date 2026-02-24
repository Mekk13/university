#pragma once
#include "UserService.h"
#include "ui_UserGUI.h"
#include "WatchlistTableModel.h"
#include "WatchlistWidget.h"

class UserGUI : public QWidget {
    Q_OBJECT
public:
    UserGUI(std::shared_ptr<User_Service> userService, QWidget* parent = nullptr);

private:
    std::shared_ptr<User_Service> user_service;
    Ui::UserGUI ui;
    std::vector<Movie> MoviesByGenre;
    int index;
    WatchlistWidget* watchwidget;
    TableModel* model;

    
private slots:
    void OnSearchByGenreButtonClicked();
    void OnNextMovieFromWatchlistButtonClicked();
    void OnAddToWatchlistButtonClicked();
    void OnDeleteFromWatchlistButtonClicked();
    void OnLikeMovieButtonClicked();
    void OnOpenWatchlistInSavedFileButtonClicked();
    void PopulateWatchlistView();
    QString movie_to_string(Movie& movie) const;
    void show_in_browser(std::string trailer);
    void showWatchlistHandler()
    {
        this->model = new TableModel(*this->user_service);
        this->watchwidget = new WatchlistWidget{ this->model };
        this->watchwidget->show();
    }
};
