#include "WatchlistTableModel.h"


int TableModel::rowCount(const QModelIndex& parent) const
{
    // Return number of movies in watchlist
    return this->serv.getWatchlistCount();
}

int TableModel::columnCount(const QModelIndex& parent) const
{
    // Adjust number of columns you want, e.g. 5
    return 5;
}

QVariant TableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    int column = index.column();

    // Get vector of movies from your service's watchlist method
    std::vector<Movie> movies = this->serv.get_watchlist();

    if (row < 0 || row >= static_cast<int>(movies.size()))
        return QVariant();

    const Movie& movie = movies[row];

    if (role == Qt::DisplayRole) {
        switch (column) {
        case 0:
            return QString::fromStdString(movie.getTitle());  // Assuming getTitle() exists
        case 1:
            return QString::fromStdString(movie.getGenre());  // Adjust with your Movie getters
        case 2:
            return QString::number(movie.getYear());
        case 3:
            return QString::number(movie.getLikes());
        case 4:
            return QString::fromStdString(movie.getTrailer());
        default:
            break;
        }
    }
    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
        case 0:
            return QString("Title");
        case 1:
            return QString("Genre");
        case 2:
            return QString("Year");
        case 3:
            return QString("Likes");
        case 4:
            return QString("Trailer");
        default:
            break;
        }
    }
    return QVariant();
}
