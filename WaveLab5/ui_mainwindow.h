/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Nov 24 11:50:39 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionWave_Supperposition;
    QAction *actionVectors;
    QAction *actionAbout_WaveLab;
    QAction *actionClose;
    QAction *actionWaveLab_Help;
    QAction *actionAbout_Qt;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab_0;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *label;
    QDoubleSpinBox *wave1_amplitude;
    QLabel *label_3;
    QDoubleSpinBox *wave1_frequency;
    QLabel *label_6;
    QFrame *line;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QLabel *label_5;
    QDoubleSpinBox *wave2_amplitude;
    QLabel *label_4;
    QDoubleSpinBox *wave2_frequency;
    QLabel *label_7;
    QDoubleSpinBox *phaseShift;
    QFrame *line_2;
    QFrame *line_3;
    QVBoxLayout *verticalLayout;
    QPushButton *runButton;
    QPushButton *stepButton;
    QPushButton *resetButton;
    QFrame *line_4;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QDoubleSpinBox *time;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QLabel *label_11;
    QLabel *label_12;
    QGridLayout *tab_0_layout;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab_1;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_16;
    QSlider *int_speed;
    QLCDNumber *lcdNumber_2;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_13;
    QSpinBox *slits;
    QFrame *line_5;
    QVBoxLayout *verticalLayout_2;
    QPushButton *int_runButton;
    QPushButton *int_stepButton;
    QPushButton *int_resetButton;
    QGridLayout *tab_1_layout;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1138, 600);
        actionWave_Supperposition = new QAction(MainWindow);
        actionWave_Supperposition->setObjectName(QString::fromUtf8("actionWave_Supperposition"));
        actionVectors = new QAction(MainWindow);
        actionVectors->setObjectName(QString::fromUtf8("actionVectors"));
        actionAbout_WaveLab = new QAction(MainWindow);
        actionAbout_WaveLab->setObjectName(QString::fromUtf8("actionAbout_WaveLab"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionWaveLab_Help = new QAction(MainWindow);
        actionWaveLab_Help->setObjectName(QString::fromUtf8("actionWaveLab_Help"));
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_0 = new QWidget();
        tab_0->setObjectName(QString::fromUtf8("tab_0"));
        gridLayout_7 = new QGridLayout(tab_0);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_8 = new QLabel(tab_0);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 0, 0, 1, 1);

        label = new QLabel(tab_0);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 1, 0, 1, 1);

        wave1_amplitude = new QDoubleSpinBox(tab_0);
        wave1_amplitude->setObjectName(QString::fromUtf8("wave1_amplitude"));
        wave1_amplitude->setMaximum(360);
        wave1_amplitude->setSingleStep(0.1);
        wave1_amplitude->setValue(1);

        gridLayout_2->addWidget(wave1_amplitude, 1, 1, 1, 1);

        label_3 = new QLabel(tab_0);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        wave1_frequency = new QDoubleSpinBox(tab_0);
        wave1_frequency->setObjectName(QString::fromUtf8("wave1_frequency"));
        wave1_frequency->setMaximum(360);
        wave1_frequency->setSingleStep(0.1);
        wave1_frequency->setValue(1);

        gridLayout_2->addWidget(wave1_frequency, 2, 1, 1, 1);

        label_6 = new QLabel(tab_0);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 0, 1, 1);

        line = new QFrame(tab_0);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::VLine);

        gridLayout_4->addWidget(line, 0, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_9 = new QLabel(tab_0);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        label_5 = new QLabel(tab_0);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        wave2_amplitude = new QDoubleSpinBox(tab_0);
        wave2_amplitude->setObjectName(QString::fromUtf8("wave2_amplitude"));
        wave2_amplitude->setMaximum(360);
        wave2_amplitude->setSingleStep(0.1);
        wave2_amplitude->setValue(1);

        gridLayout->addWidget(wave2_amplitude, 1, 1, 1, 1);

        label_4 = new QLabel(tab_0);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        wave2_frequency = new QDoubleSpinBox(tab_0);
        wave2_frequency->setObjectName(QString::fromUtf8("wave2_frequency"));
        wave2_frequency->setMaximum(360);
        wave2_frequency->setSingleStep(0.1);
        wave2_frequency->setValue(0.9);

        gridLayout->addWidget(wave2_frequency, 2, 1, 1, 1);

        label_7 = new QLabel(tab_0);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        phaseShift = new QDoubleSpinBox(tab_0);
        phaseShift->setObjectName(QString::fromUtf8("phaseShift"));
        phaseShift->setMaximum(360);
        phaseShift->setSingleStep(0.1);

        gridLayout->addWidget(phaseShift, 3, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 2, 1, 1);

        line_2 = new QFrame(tab_0);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShadow(QFrame::Plain);
        line_2->setFrameShape(QFrame::VLine);

        gridLayout_4->addWidget(line_2, 0, 3, 1, 1);

        line_3 = new QFrame(tab_0);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShadow(QFrame::Plain);
        line_3->setFrameShape(QFrame::VLine);

        gridLayout_4->addWidget(line_3, 0, 5, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        runButton = new QPushButton(tab_0);
        runButton->setObjectName(QString::fromUtf8("runButton"));

        verticalLayout->addWidget(runButton);

        stepButton = new QPushButton(tab_0);
        stepButton->setObjectName(QString::fromUtf8("stepButton"));

        verticalLayout->addWidget(stepButton);

        resetButton = new QPushButton(tab_0);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        verticalLayout->addWidget(resetButton);


        gridLayout_4->addLayout(verticalLayout, 0, 6, 1, 1);

        line_4 = new QFrame(tab_0);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShadow(QFrame::Plain);
        line_4->setFrameShape(QFrame::HLine);

        gridLayout_4->addWidget(line_4, 1, 0, 1, 7);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_10 = new QLabel(tab_0);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        time = new QDoubleSpinBox(tab_0);
        time->setObjectName(QString::fromUtf8("time"));
        time->setDecimals(3);
        time->setMinimum(0);
        time->setSingleStep(0.1);
        time->setValue(0.1);

        gridLayout_3->addWidget(time, 0, 1, 1, 1);

        label_2 = new QLabel(tab_0);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        lcdNumber = new QLCDNumber(tab_0);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setFrameShadow(QFrame::Plain);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(0));

        gridLayout_3->addWidget(lcdNumber, 1, 1, 1, 1);

        label_11 = new QLabel(tab_0);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 2, 0, 1, 1);

        label_12 = new QLabel(tab_0);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 3, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_3, 0, 4, 1, 1);


        gridLayout_7->addLayout(gridLayout_4, 0, 0, 1, 1);

        tab_0_layout = new QGridLayout();
        tab_0_layout->setSpacing(6);
        tab_0_layout->setObjectName(QString::fromUtf8("tab_0_layout"));
        tab_0_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tab_0_layout->addItem(verticalSpacer_2, 0, 0, 1, 1);


        gridLayout_7->addLayout(tab_0_layout, 1, 0, 1, 1);

        tabWidget->addTab(tab_0, QString());
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        gridLayout_6 = new QGridLayout(tab_1);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalSpacer = new QSpacerItem(526, 99, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_16 = new QLabel(tab_1);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_16);

        int_speed = new QSlider(tab_1);
        int_speed->setObjectName(QString::fromUtf8("int_speed"));
        int_speed->setMinimum(0);
        int_speed->setMaximum(500);
        int_speed->setSingleStep(1);
        int_speed->setValue(0);
        int_speed->setSliderPosition(0);
        int_speed->setOrientation(Qt::Horizontal);
        int_speed->setInvertedControls(false);

        horizontalLayout_4->addWidget(int_speed);


        verticalLayout_3->addLayout(horizontalLayout_4);

        lcdNumber_2 = new QLCDNumber(tab_1);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        sizePolicy.setHeightForWidth(lcdNumber_2->sizePolicy().hasHeightForWidth());
        lcdNumber_2->setSizePolicy(sizePolicy);
        lcdNumber_2->setFrameShadow(QFrame::Plain);
        lcdNumber_2->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_2->setProperty("value", QVariant(0));

        verticalLayout_3->addWidget(lcdNumber_2);


        gridLayout_6->addLayout(verticalLayout_3, 0, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_13 = new QLabel(tab_1);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout->addWidget(label_13);

        slits = new QSpinBox(tab_1);
        slits->setObjectName(QString::fromUtf8("slits"));
        slits->setValue(6);

        horizontalLayout->addWidget(slits);


        verticalLayout_5->addLayout(horizontalLayout);


        horizontalLayout_7->addLayout(verticalLayout_5);

        line_5 = new QFrame(tab_1);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShadow(QFrame::Plain);
        line_5->setFrameShape(QFrame::VLine);

        horizontalLayout_7->addWidget(line_5);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        int_runButton = new QPushButton(tab_1);
        int_runButton->setObjectName(QString::fromUtf8("int_runButton"));

        verticalLayout_2->addWidget(int_runButton);

        int_stepButton = new QPushButton(tab_1);
        int_stepButton->setObjectName(QString::fromUtf8("int_stepButton"));

        verticalLayout_2->addWidget(int_stepButton);

        int_resetButton = new QPushButton(tab_1);
        int_resetButton->setObjectName(QString::fromUtf8("int_resetButton"));

        verticalLayout_2->addWidget(int_resetButton);


        horizontalLayout_7->addLayout(verticalLayout_2);


        gridLayout_6->addLayout(horizontalLayout_7, 0, 2, 1, 1);

        tab_1_layout = new QGridLayout();
        tab_1_layout->setSpacing(6);
        tab_1_layout->setObjectName(QString::fromUtf8("tab_1_layout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        tab_1_layout->addItem(verticalSpacer, 0, 0, 1, 1);


        gridLayout_6->addLayout(tab_1_layout, 1, 0, 1, 3);

        tabWidget->addTab(tab_1, QString());

        gridLayout_5->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1138, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionClose);
        menuHelp->addAction(actionAbout_WaveLab);
        menuHelp->addAction(actionAbout_Qt);
        menuHelp->addAction(actionWaveLab_Help);

        retranslateUi(MainWindow);
        QObject::connect(actionClose, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(int_speed, SIGNAL(valueChanged(int)), lcdNumber_2, SLOT(display(int)));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "WaveLab", 0, QApplication::UnicodeUTF8));
        actionWave_Supperposition->setText(QApplication::translate("MainWindow", "Wave Supperposition", 0, QApplication::UnicodeUTF8));
        actionVectors->setText(QApplication::translate("MainWindow", "Vectors", 0, QApplication::UnicodeUTF8));
        actionAbout_WaveLab->setText(QApplication::translate("MainWindow", "About WaveLab", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        actionWaveLab_Help->setText(QApplication::translate("MainWindow", "WaveLab Help", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindow", "About Qt", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Wave A (Green)", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Amplitude (m)", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Frequency (Pi * rad/s)", 0, QApplication::UnicodeUTF8));
        label_6->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Wave B (Red)", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Amplitude (m)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Frequency (Pi * rad/s)", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Phase Shift (Pi * rad)", 0, QApplication::UnicodeUTF8));
        runButton->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        stepButton->setText(QApplication::translate("MainWindow", "Step", 0, QApplication::UnicodeUTF8));
        resetButton->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Time Interval (s)", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Elapsed Time (s)", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        label_12->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_0), QApplication::translate("MainWindow", "Superposition", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "Render Delay (ms)", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "Slits", 0, QApplication::UnicodeUTF8));
        int_runButton->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        int_stepButton->setText(QApplication::translate("MainWindow", "Step", 0, QApplication::UnicodeUTF8));
        int_resetButton->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "Intensity", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
