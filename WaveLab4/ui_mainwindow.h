/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Fri Sep 4 17:31:16 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionWave_Supperposition;
    QAction *actionVectors;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_8;
    QLabel *label;
    QDoubleSpinBox *wave1_amplitude;
    QLabel *label_3;
    QDoubleSpinBox *wave1_frequency;
    QFrame *line;
    QLabel *label_9;
    QLabel *label_5;
    QDoubleSpinBox *wave2_amplitude;
    QLabel *label_4;
    QDoubleSpinBox *wave2_frequency;
    QLabel *label_7;
    QDoubleSpinBox *phaseShift;
    QFrame *line_2;
    QLabel *label_10;
    QDoubleSpinBox *time;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QPushButton *runButton;
    QPushButton *stepButton;
    QPushButton *resetButton;
    QCheckBox *wave1_toggle;
    QCheckBox *wave2_toggle;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuView;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(707, 641);
        actionWave_Supperposition = new QAction(MainWindow);
        actionWave_Supperposition->setObjectName(QString::fromUtf8("actionWave_Supperposition"));
        actionVectors = new QAction(MainWindow);
        actionVectors->setObjectName(QString::fromUtf8("actionVectors"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        wave1_amplitude = new QDoubleSpinBox(centralWidget);
        wave1_amplitude->setObjectName(QString::fromUtf8("wave1_amplitude"));
        wave1_amplitude->setMaximum(360);
        wave1_amplitude->setSingleStep(0.1);

        gridLayout->addWidget(wave1_amplitude, 1, 2, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 2);

        wave1_frequency = new QDoubleSpinBox(centralWidget);
        wave1_frequency->setObjectName(QString::fromUtf8("wave1_frequency"));
        wave1_frequency->setMaximum(360);
        wave1_frequency->setSingleStep(0.1);

        gridLayout->addWidget(wave1_frequency, 2, 2, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line, 3, 0, 1, 3);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 4, 0, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        wave2_amplitude = new QDoubleSpinBox(centralWidget);
        wave2_amplitude->setObjectName(QString::fromUtf8("wave2_amplitude"));
        wave2_amplitude->setMaximum(360);
        wave2_amplitude->setSingleStep(0.1);

        gridLayout->addWidget(wave2_amplitude, 5, 2, 1, 1);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 6, 0, 1, 2);

        wave2_frequency = new QDoubleSpinBox(centralWidget);
        wave2_frequency->setObjectName(QString::fromUtf8("wave2_frequency"));
        wave2_frequency->setMaximum(360);
        wave2_frequency->setSingleStep(0.1);

        gridLayout->addWidget(wave2_frequency, 6, 2, 1, 1);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 7, 0, 1, 2);

        phaseShift = new QDoubleSpinBox(centralWidget);
        phaseShift->setObjectName(QString::fromUtf8("phaseShift"));
        phaseShift->setMaximum(360);
        phaseShift->setSingleStep(0.1);

        gridLayout->addWidget(phaseShift, 7, 2, 1, 1);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setAutoFillBackground(false);
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::HLine);

        gridLayout->addWidget(line_2, 8, 0, 1, 3);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 9, 0, 1, 1);

        time = new QDoubleSpinBox(centralWidget);
        time->setObjectName(QString::fromUtf8("time"));
        time->setDecimals(3);
        time->setMinimum(0);
        time->setSingleStep(0.1);
        time->setValue(0.1);

        gridLayout->addWidget(time, 9, 2, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 10, 0, 1, 1);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setFrameShadow(QFrame::Plain);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(0));

        gridLayout->addWidget(lcdNumber, 10, 2, 1, 1);

        runButton = new QPushButton(centralWidget);
        runButton->setObjectName(QString::fromUtf8("runButton"));

        gridLayout->addWidget(runButton, 11, 0, 1, 1);

        stepButton = new QPushButton(centralWidget);
        stepButton->setObjectName(QString::fromUtf8("stepButton"));

        gridLayout->addWidget(stepButton, 11, 1, 1, 2);

        resetButton = new QPushButton(centralWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        gridLayout->addWidget(resetButton, 12, 0, 1, 1);

        wave1_toggle = new QCheckBox(centralWidget);
        wave1_toggle->setObjectName(QString::fromUtf8("wave1_toggle"));
        wave1_toggle->setChecked(true);

        gridLayout->addWidget(wave1_toggle, 13, 0, 1, 1);

        wave2_toggle = new QCheckBox(centralWidget);
        wave2_toggle->setObjectName(QString::fromUtf8("wave2_toggle"));
        wave2_toggle->setChecked(true);

        gridLayout->addWidget(wave2_toggle, 14, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(441, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 105, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 707, 22));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuView->menuAction());
        menuView->addAction(actionWave_Supperposition);
        menuView->addAction(actionVectors);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "WaveLab", 0, QApplication::UnicodeUTF8));
        actionWave_Supperposition->setText(QApplication::translate("MainWindow", "Wave Supperposition", 0, QApplication::UnicodeUTF8));
        actionVectors->setText(QApplication::translate("MainWindow", "Vectors", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Wave A (Green)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Amplitude (m)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Frequency (Pi * rad/s)", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Wave B (Red)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Amplitude (m)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Frequency (Pi * rad/s)", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Phase Shift (Pi * rad)", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Time Interval (s)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Elapsed Time (s)", 0, QApplication::UnicodeUTF8));
        runButton->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        stepButton->setText(QApplication::translate("MainWindow", "Step", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        wave1_toggle->setText(QApplication::translate("MainWindow", "Show Wave A", 0, QApplication::UnicodeUTF8));
        wave2_toggle->setText(QApplication::translate("MainWindow", "Show Wave B", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
