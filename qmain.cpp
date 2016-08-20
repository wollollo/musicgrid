#include <qt/QtWidgets/QApplication>
#include <qt/QtCore/QStringList>
#include <qt/QtCore/QStringListModel>
#include <qt/QtCore/QAbstractItemModel>
#include <qt/QtCore/QAbstractTableModel>
#include <qt/QtWidgets/QTreeView>
#include <qt/QtWidgets/QTableView>

#include "sketches.h"
#include "tracklistmodel.h"

TrackListModel::TrackListModel(QObject* parent, MusicGrid::TrackList* tracks)
    : QAbstractTableModel(parent), tracks_{tracks}
{
}

int TrackListModel::rowCount(const QModelIndex&) const
{
    return tracks_->size();
}

int TrackListModel::columnCount(const QModelIndex&) const
{
    return 2;
}

QVariant TrackListModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole) {
        //return QString("Row%1, Column%2").arg(index.row() + 1).arg(index.column() + 1);
        if (index.column() == 0)
            return QString("<Artist goes here>");
            //return tracks_[index.row()].artist();
        if (index.column() == 1)
            return QString::fromStdString((*tracks_)[index.row()].title().to8Bit());
    }
    return QVariant();
}

int main(int argc, char* argv[])
{
    QApplication app(argc,argv);

    //DUMMIES
    //QStringList numbers;
    //numbers << "one" << "two" << "three";
    //END DUMMIES
    MusicGrid::TrackList tracks;
    tracks.populate("testtree","");
    
    //QAbstractItemModel* model = new QStringListModel(numbers);
    QAbstractItemModel* myModel = new TrackListModel(0, &tracks);

    //QTreeView* view = new QTreeView;
    //view->setModel(model);

    QTableView* myView = new QTableView;
    myView->setModel(myModel);

    myView->show();
    //view->show();
    return app.exec();
}
