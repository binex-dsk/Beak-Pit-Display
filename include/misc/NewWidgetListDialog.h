#ifndef NEWWIDGETLISTDIALOG_H
#define NEWWIDGETLISTDIALOG_H

#include <QDialog>

#include <QVBoxLayout>
#include <QListWidget>
#include <QDialogButtonBox>

#include "dialogs/NewWidgetDialog.h"

class NewWidgetListDialog : public QDialog
{
    Q_OBJECT
private:
    QVBoxLayout *m_layout;
    QListWidget *m_list;

    QDialogButtonBox *m_buttonBox;

    void constructList();
    QAction *createWidgetAction(const QString &text, const QString &ntTopic, const NewWidgetDialog::WidgetTypes &widgetType);
public:
    NewWidgetListDialog();
    virtual ~NewWidgetListDialog();

    void showNewWidgetDialog(NewWidgetDialog::WidgetTypes widgetType, std::string ntTopic);

    void keyPressEvent(QKeyEvent *event);

public slots:
    void emitWidget(BaseWidget *widget, WidgetData data);

signals:
    void widgetReady(BaseWidget *widget, WidgetData data);
};

#endif // NEWWIDGETLISTDIALOG_H