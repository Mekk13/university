/****************************************************************************
** Meta object code from reading C++ file 'UserGUI.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../UserGUI.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UserGUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN7UserGUIE_t {};
} // unnamed namespace

template <> constexpr inline auto UserGUI::qt_create_metaobjectdata<qt_meta_tag_ZN7UserGUIE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "UserGUI",
        "OnSearchByGenreButtonClicked",
        "",
        "OnNextMovieFromWatchlistButtonClicked",
        "OnAddToWatchlistButtonClicked",
        "OnDeleteFromWatchlistButtonClicked",
        "OnLikeMovieButtonClicked",
        "OnOpenWatchlistInSavedFileButtonClicked",
        "PopulateWatchlistView",
        "movie_to_string",
        "Movie&",
        "movie",
        "show_in_browser",
        "std::string",
        "trailer",
        "showWatchlistHandler"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'OnSearchByGenreButtonClicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'OnNextMovieFromWatchlistButtonClicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'OnAddToWatchlistButtonClicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'OnDeleteFromWatchlistButtonClicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'OnLikeMovieButtonClicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'OnOpenWatchlistInSavedFileButtonClicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'PopulateWatchlistView'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'movie_to_string'
        QtMocHelpers::SlotData<QString(Movie &) const>(9, 2, QMC::AccessPrivate, QMetaType::QString, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Slot 'show_in_browser'
        QtMocHelpers::SlotData<void(std::string)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 13, 14 },
        }}),
        // Slot 'showWatchlistHandler'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<UserGUI, qt_meta_tag_ZN7UserGUIE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject UserGUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7UserGUIE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7UserGUIE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7UserGUIE_t>.metaTypes,
    nullptr
} };

void UserGUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<UserGUI *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->OnSearchByGenreButtonClicked(); break;
        case 1: _t->OnNextMovieFromWatchlistButtonClicked(); break;
        case 2: _t->OnAddToWatchlistButtonClicked(); break;
        case 3: _t->OnDeleteFromWatchlistButtonClicked(); break;
        case 4: _t->OnLikeMovieButtonClicked(); break;
        case 5: _t->OnOpenWatchlistInSavedFileButtonClicked(); break;
        case 6: _t->PopulateWatchlistView(); break;
        case 7: { QString _r = _t->movie_to_string((*reinterpret_cast< std::add_pointer_t<Movie&>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->show_in_browser((*reinterpret_cast< std::add_pointer_t<std::string>>(_a[1]))); break;
        case 9: _t->showWatchlistHandler(); break;
        default: ;
        }
    }
}

const QMetaObject *UserGUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserGUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7UserGUIE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int UserGUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
