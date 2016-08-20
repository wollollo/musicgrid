#ifndef TRACKLISTMODEL_H
#define TRACKLISTMODEL_H

#include <QAbstractTableModel>

#include "sketches.h"

class TrackListModel : public QAbstractTableModel {
    Q_OBJECT
  public:
    TrackListModel(QObject* parent, MusicGrid::TrackList* tracks);
    int rowCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE ;
    int columnCount(const QModelIndex& parent = QModelIndex()) const Q_DECL_OVERRIDE ;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE ;
  private:
    MusicGrid::TrackList* tracks_;
};

#endif //TRACKLISTMODEL_H
