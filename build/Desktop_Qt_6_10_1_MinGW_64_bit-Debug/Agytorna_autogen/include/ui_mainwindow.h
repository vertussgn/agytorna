/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *sidebar;
    QVBoxLayout *verticalLayout;
    QPushButton *homeButton;
    QPushButton *languagesButton;
    QPushButton *profileButton;
    QPushButton *statsButton;
    QSpacerItem *verticalSpacer;
    QPushButton *logoutButton;
    QStackedWidget *stackedWidget;
    QWidget *mainMenuPage;
    QVBoxLayout *verticalLayout_2;
    QLabel *welcomeLabel;
    QLabel *subtitleLabel;
    QHBoxLayout *statsLayout;
    QFrame *statsCard;
    QVBoxLayout *verticalLayout_10;
    QLabel *statsIcon1;
    QLabel *completedLabel;
    QLabel *completedText;
    QFrame *statsCard_2;
    QVBoxLayout *verticalLayout_11;
    QLabel *statsIcon2;
    QLabel *wordsLearnedLabel;
    QLabel *wordsLearnedText;
    QFrame *statsCard_3;
    QVBoxLayout *verticalLayout_12;
    QLabel *statsIcon3;
    QLabel *streakLabel;
    QLabel *streakText;
    QLabel *sectionLabel;
    QGridLayout *languageGrid;
    QPushButton *hungarianButton;
    QPushButton *englishButton;
    QPushButton *germanButton;
    QPushButton *russianButton;
    QSpacerItem *verticalSpacer_2;
    QWidget *categoryPage;
    QVBoxLayout *verticalLayout_3;
    QLabel *categoryTitle;
    QLabel *selectedLanguageLabel;
    QGridLayout *categoryGrid;
    QPushButton *vocabularyButton;
    QPushButton *grammarButton;
    QPushButton *sentencesButton;
    QPushButton *listeningButton;
    QLabel *difficultyTitle;
    QHBoxLayout *difficultyLayout;
    QPushButton *beginnerButton;
    QPushButton *intermediateButton;
    QPushButton *advancedButton;
    QHBoxLayout *categoryNavLayout;
    QPushButton *backFromCategoryButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *startQuizButton;
    QSpacerItem *verticalSpacer_3;
    QWidget *quizPage;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *quizHeaderLayout;
    QLabel *questionNumberLabel;
    QSpacerItem *horizontalSpacer_3;
    QLabel *currentScoreLabel;
    QLabel *categoryInfoLabel;
    QFrame *questionCard;
    QVBoxLayout *verticalLayout_5;
    QLabel *questionLabel;
    QLabel *wordLabel;
    QWidget *answersWidget;
    QVBoxLayout *answersLayout;
    QLabel *feedbackLabel;
    QHBoxLayout *quizNavLayout;
    QPushButton *quitQuizButton;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *nextQuestionButton;
    QWidget *resultsPage;
    QVBoxLayout *verticalLayout_6;
    QLabel *resultsTitle;
    QSpacerItem *verticalSpacer_4;
    QFrame *resultsCard;
    QVBoxLayout *verticalLayout_7;
    QLabel *scoreLabel;
    QLabel *resultLabel;
    QLabel *percentageLabel;
    QLabel *pointsLabel;
    QLabel *messageLabel;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *resultsButtonLayout;
    QPushButton *backToMenuButton;
    QPushButton *restartSameButton;
    QPushButton *nextLevelButton;
    QWidget *statisticsPage;
    QVBoxLayout *verticalLayout_8;
    QLabel *statsPageTitle;
    QGridLayout *statsGridLayout;
    QFrame *statsCardHu;
    QVBoxLayout *verticalLayout_13;
    QLabel *langIcon1;
    QLabel *langName1;
    QLabel *langStats1;
    QFrame *statsCardEn;
    QVBoxLayout *verticalLayout_14;
    QLabel *langIcon2;
    QLabel *langName2;
    QLabel *langStats2;
    QFrame *statsCardDe;
    QVBoxLayout *verticalLayout_15;
    QLabel *langIcon3;
    QLabel *langName3;
    QLabel *langStats3;
    QFrame *statsCardRu;
    QVBoxLayout *verticalLayout_16;
    QLabel *langIcon4;
    QLabel *langName4;
    QLabel *langStats4;
    QPushButton *backFromStatsButton;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 724);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #f5f5f5;\n"
"}\n"
"\n"
"QLabel#welcomeLabel {\n"
"    font-size: 32px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QLabel#sectionLabel {\n"
"    font-size: 20px;\n"
"    font-weight: bold;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 8px;\n"
"    padding: 12px 24px;\n"
"    font-size: 15px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #2980b9;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #21618c;\n"
"}\n"
"\n"
"QPushButton#sidebarButton {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    color: white;\n"
"    font-size: 24px;\n"
"    min-width: 50px;\n"
"    max-width: 50px;\n"
"    min-height: 50px;\n"
"    max-height: 50px;\n"
"}\n"
"\n"
"QPushButton#languageButton {\n"
"    background-color: white;\n"
"    color: #2c3e50;\n"
"    border: 2px solid #3498db;\n"
""
                        "    border-radius: 12px;\n"
"    padding: 20px;\n"
"    font-size: 18px;\n"
"    min-height: 80px;\n"
"}\n"
"\n"
"QPushButton#languageButton:hover {\n"
"    background-color: #3498db;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton#categoryButton {\n"
"    background-color: white;\n"
"    color: #2c3e50;\n"
"    border: 2px solid #e74c3c;\n"
"    border-radius: 10px;\n"
"    padding: 15px;\n"
"    font-size: 16px;\n"
"    min-height: 60px;\n"
"}\n"
"\n"
"QPushButton#categoryButton:hover {\n"
"    background-color: #e74c3c;\n"
"    color: white;\n"
"}\n"
"\n"
"QPushButton#difficultyButton {\n"
"    background-color: white;\n"
"    color: #2c3e50;\n"
"    border: 2px solid #f39c12;\n"
"    border-radius: 10px;\n"
"    padding: 15px;\n"
"    font-size: 16px;\n"
"    min-height: 60px;\n"
"}\n"
"\n"
"QPushButton#difficultyButton:hover {\n"
"    background-color: #f39c12;\n"
"    color: white;\n"
"}\n"
"\n"
"QFrame#sidebar {\n"
"    background-color: #2c3e50;\n"
"    border-top-left-radius: 20px;\n"
"    border-bot"
                        "tom-left-radius: 20px;\n"
"}\n"
"\n"
"QFrame#statsCard {\n"
"    background-color: white;\n"
"    border-radius: 15px;\n"
"    padding: 20px;\n"
"    border: 2px solid #ecf0f1;\n"
"}\n"
"\n"
"QFrame#questionCard {\n"
"    background-color: white;\n"
"    border-radius: 20px;\n"
"    padding: 30px;\n"
"    border: 3px solid #3498db;\n"
"}\n"
"\n"
"QScrollArea {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid #bdc3c7;\n"
"    border-radius: 20px;\n"
"    padding: 12px 24px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #3498db;\n"
"}\n"
"\n"
"QLabel#questionLabel {\n"
"    font-size: 24px;\n"
"    color: #2c3e50;\n"
"    padding: 20px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QLabel#wordLabel {\n"
"    font-size: 36px;\n"
"    color: #e74c3c;\n"
"    padding: 20px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QLabel#feedbackLabel {\n"
"    font-size: 18px;\n"
"    padding: 15px;\n"
""
                        "    border-radius: 10px;\n"
"}\n"
"\n"
"QLabel#resultLabel {\n"
"    font-size: 48px;\n"
"    font-weight: bold;\n"
"    color: #27ae60;\n"
"    padding: 20px;\n"
"}\n"
"\n"
"QLabel#categoryLabel {\n"
"    font-size: 16px;\n"
"    color: #7f8c8d;\n"
"    padding: 5px;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sidebar = new QFrame(centralwidget);
        sidebar->setObjectName("sidebar");
        sidebar->setMinimumSize(QSize(80, 0));
        sidebar->setMaximumSize(QSize(80, 16777215));
        sidebar->setFrameShape(QFrame::Shape::StyledPanel);
        verticalLayout = new QVBoxLayout(sidebar);
        verticalLayout->setSpacing(30);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(15, 30, 15, 30);
        homeButton = new QPushButton(sidebar);
        homeButton->setObjectName("homeButton");
        homeButton->setMinimumSize(QSize(50, 50));
        homeButton->setMaximumSize(QSize(50, 50));
        homeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"        border-color: rgb(255, 255, 255);\n"
"           background-color: rgba(255, 255, 255, 0.1);\n"
"           border: none;\n"
"           border-radius: 10px;\n"
"       }\n"
"       QPushButton:hover {\n"
"           background-color: rgba(255, 255, 255, 0.2);\n"
"       }"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("go-home")));
        homeButton->setIcon(icon);
        homeButton->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(homeButton);

        languagesButton = new QPushButton(sidebar);
        languagesButton->setObjectName("languagesButton");
        languagesButton->setMinimumSize(QSize(50, 50));
        languagesButton->setMaximumSize(QSize(50, 50));
        languagesButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"           background-color: rgba(255, 255, 255, 0.1);\n"
"           border: none;\n"
"           border-radius: 10px;\n"
"       }\n"
"       QPushButton:hover {\n"
"           background-color: rgba(255, 255, 255, 0.2);\n"
"       }"));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("preferences-desktop-locale")));
        languagesButton->setIcon(icon1);
        languagesButton->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(languagesButton);

        profileButton = new QPushButton(sidebar);
        profileButton->setObjectName("profileButton");
        profileButton->setMinimumSize(QSize(50, 50));
        profileButton->setMaximumSize(QSize(50, 50));
        profileButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"           background-color: rgba(255, 255, 255, 0.1);\n"
"           border: none;\n"
"           border-radius: 10px;\n"
"       }\n"
"       QPushButton:hover {\n"
"           background-color: rgba(255, 255, 255, 0.2);\n"
"\n"
"       }"));
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("user-available")));
        profileButton->setIcon(icon2);
        profileButton->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(profileButton);

        statsButton = new QPushButton(sidebar);
        statsButton->setObjectName("statsButton");
        statsButton->setMinimumSize(QSize(50, 50));
        statsButton->setMaximumSize(QSize(50, 50));
        statsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"           background-color: rgba(255, 255, 255, 0.1);\n"
"           border: none;\n"
"           border-radius: 10px;\n"
"       }\n"
"       QPushButton:hover {\n"
"           background-color: rgba(255, 255, 255, 0.2);\n"
"       }"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::AddressBookNew));
        statsButton->setIcon(icon3);
        statsButton->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(statsButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        logoutButton = new QPushButton(sidebar);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setMinimumSize(QSize(50, 50));
        logoutButton->setMaximumSize(QSize(50, 50));
        logoutButton->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        logoutButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"                  background-color: rgba(255, 255, 255, 0.1);\n"
"                  border: none;\n"
"                  border-radius: 10px;\n"
"              }\n"
"              QPushButton:hover {\n"
"                  background-color: rgba(255, 255, 255, 0.2);\n"
"              }"));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::ApplicationExit));
        logoutButton->setIcon(icon4);
        logoutButton->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(logoutButton);


        horizontalLayout->addWidget(sidebar);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        mainMenuPage = new QWidget();
        mainMenuPage->setObjectName("mainMenuPage");
        verticalLayout_2 = new QVBoxLayout(mainMenuPage);
        verticalLayout_2->setSpacing(30);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(50, 40, 50, 40);
        welcomeLabel = new QLabel(mainMenuPage);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(welcomeLabel);

        subtitleLabel = new QLabel(mainMenuPage);
        subtitleLabel->setObjectName("subtitleLabel");
        subtitleLabel->setStyleSheet(QString::fromUtf8("font-size: 18px; color: #7f8c8d;"));
        subtitleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(subtitleLabel);

        statsLayout = new QHBoxLayout();
        statsLayout->setObjectName("statsLayout");
        statsCard = new QFrame(mainMenuPage);
        statsCard->setObjectName("statsCard");
        statsCard->setMinimumSize(QSize(150, 100));
        verticalLayout_10 = new QVBoxLayout(statsCard);
        verticalLayout_10->setObjectName("verticalLayout_10");
        statsIcon1 = new QLabel(statsCard);
        statsIcon1->setObjectName("statsIcon1");
        statsIcon1->setStyleSheet(QString::fromUtf8("font-size: 32px;"));
        statsIcon1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(statsIcon1);

        completedLabel = new QLabel(statsCard);
        completedLabel->setObjectName("completedLabel");
        completedLabel->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold; color: #27ae60;"));
        completedLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(completedLabel);

        completedText = new QLabel(statsCard);
        completedText->setObjectName("completedText");
        completedText->setStyleSheet(QString::fromUtf8("font-size: 12px; color: #7f8c8d;"));
        completedText->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(completedText);


        statsLayout->addWidget(statsCard);

        statsCard_2 = new QFrame(mainMenuPage);
        statsCard_2->setObjectName("statsCard_2");
        statsCard_2->setMinimumSize(QSize(150, 100));
        verticalLayout_11 = new QVBoxLayout(statsCard_2);
        verticalLayout_11->setObjectName("verticalLayout_11");
        statsIcon2 = new QLabel(statsCard_2);
        statsIcon2->setObjectName("statsIcon2");
        statsIcon2->setStyleSheet(QString::fromUtf8("font-size: 32px;"));
        statsIcon2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_11->addWidget(statsIcon2);

        wordsLearnedLabel = new QLabel(statsCard_2);
        wordsLearnedLabel->setObjectName("wordsLearnedLabel");
        wordsLearnedLabel->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold; color: #3498db;"));
        wordsLearnedLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_11->addWidget(wordsLearnedLabel);

        wordsLearnedText = new QLabel(statsCard_2);
        wordsLearnedText->setObjectName("wordsLearnedText");
        wordsLearnedText->setStyleSheet(QString::fromUtf8("font-size: 12px; color: #7f8c8d;"));
        wordsLearnedText->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_11->addWidget(wordsLearnedText);


        statsLayout->addWidget(statsCard_2);

        statsCard_3 = new QFrame(mainMenuPage);
        statsCard_3->setObjectName("statsCard_3");
        statsCard_3->setMinimumSize(QSize(150, 100));
        verticalLayout_12 = new QVBoxLayout(statsCard_3);
        verticalLayout_12->setObjectName("verticalLayout_12");
        statsIcon3 = new QLabel(statsCard_3);
        statsIcon3->setObjectName("statsIcon3");
        statsIcon3->setStyleSheet(QString::fromUtf8("font-size: 32px;"));
        statsIcon3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_12->addWidget(statsIcon3);

        streakLabel = new QLabel(statsCard_3);
        streakLabel->setObjectName("streakLabel");
        streakLabel->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold; color: #e74c3c;"));
        streakLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_12->addWidget(streakLabel);

        streakText = new QLabel(statsCard_3);
        streakText->setObjectName("streakText");
        streakText->setStyleSheet(QString::fromUtf8("font-size: 12px; color: #7f8c8d;"));
        streakText->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_12->addWidget(streakText);


        statsLayout->addWidget(statsCard_3);


        verticalLayout_2->addLayout(statsLayout);

        sectionLabel = new QLabel(mainMenuPage);
        sectionLabel->setObjectName("sectionLabel");
        sectionLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(sectionLabel);

        languageGrid = new QGridLayout();
        languageGrid->setSpacing(20);
        languageGrid->setObjectName("languageGrid");
        hungarianButton = new QPushButton(mainMenuPage);
        hungarianButton->setObjectName("hungarianButton");
        hungarianButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        languageGrid->addWidget(hungarianButton, 0, 0, 1, 1);

        englishButton = new QPushButton(mainMenuPage);
        englishButton->setObjectName("englishButton");
        englishButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        languageGrid->addWidget(englishButton, 0, 1, 1, 1);

        germanButton = new QPushButton(mainMenuPage);
        germanButton->setObjectName("germanButton");
        germanButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        languageGrid->addWidget(germanButton, 1, 0, 1, 1);

        russianButton = new QPushButton(mainMenuPage);
        russianButton->setObjectName("russianButton");
        russianButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        languageGrid->addWidget(russianButton, 1, 1, 1, 1);


        verticalLayout_2->addLayout(languageGrid);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        stackedWidget->addWidget(mainMenuPage);
        categoryPage = new QWidget();
        categoryPage->setObjectName("categoryPage");
        verticalLayout_3 = new QVBoxLayout(categoryPage);
        verticalLayout_3->setSpacing(30);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(50, 40, 50, 40);
        categoryTitle = new QLabel(categoryPage);
        categoryTitle->setObjectName("categoryTitle");
        categoryTitle->setStyleSheet(QString::fromUtf8("font-size: 28px; font-weight: bold; color: #2c3e50;"));
        categoryTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(categoryTitle);

        selectedLanguageLabel = new QLabel(categoryPage);
        selectedLanguageLabel->setObjectName("selectedLanguageLabel");
        selectedLanguageLabel->setStyleSheet(QString::fromUtf8("font-size: 16px; color: #7f8c8d;"));
        selectedLanguageLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(selectedLanguageLabel);

        categoryGrid = new QGridLayout();
        categoryGrid->setSpacing(20);
        categoryGrid->setObjectName("categoryGrid");
        vocabularyButton = new QPushButton(categoryPage);
        vocabularyButton->setObjectName("vocabularyButton");
        vocabularyButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        categoryGrid->addWidget(vocabularyButton, 0, 0, 1, 1);

        grammarButton = new QPushButton(categoryPage);
        grammarButton->setObjectName("grammarButton");
        grammarButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        categoryGrid->addWidget(grammarButton, 0, 1, 1, 1);

        sentencesButton = new QPushButton(categoryPage);
        sentencesButton->setObjectName("sentencesButton");
        sentencesButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        categoryGrid->addWidget(sentencesButton, 1, 0, 1, 1);

        listeningButton = new QPushButton(categoryPage);
        listeningButton->setObjectName("listeningButton");
        listeningButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        categoryGrid->addWidget(listeningButton, 1, 1, 1, 1);


        verticalLayout_3->addLayout(categoryGrid);

        difficultyTitle = new QLabel(categoryPage);
        difficultyTitle->setObjectName("difficultyTitle");
        difficultyTitle->setStyleSheet(QString::fromUtf8("font-size: 24px; font-weight: bold; color: #2c3e50;"));
        difficultyTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(difficultyTitle);

        difficultyLayout = new QHBoxLayout();
        difficultyLayout->setSpacing(20);
        difficultyLayout->setObjectName("difficultyLayout");
        beginnerButton = new QPushButton(categoryPage);
        beginnerButton->setObjectName("beginnerButton");
        beginnerButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        beginnerButton->setCheckable(false);
        beginnerButton->setAutoExclusive(false);

        difficultyLayout->addWidget(beginnerButton);

        intermediateButton = new QPushButton(categoryPage);
        intermediateButton->setObjectName("intermediateButton");
        intermediateButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        difficultyLayout->addWidget(intermediateButton);

        advancedButton = new QPushButton(categoryPage);
        advancedButton->setObjectName("advancedButton");
        advancedButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        difficultyLayout->addWidget(advancedButton);


        verticalLayout_3->addLayout(difficultyLayout);

        categoryNavLayout = new QHBoxLayout();
        categoryNavLayout->setObjectName("categoryNavLayout");
        backFromCategoryButton = new QPushButton(categoryPage);
        backFromCategoryButton->setObjectName("backFromCategoryButton");
        backFromCategoryButton->setMinimumSize(QSize(150, 50));
        backFromCategoryButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        categoryNavLayout->addWidget(backFromCategoryButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        categoryNavLayout->addItem(horizontalSpacer_2);

        startQuizButton = new QPushButton(categoryPage);
        startQuizButton->setObjectName("startQuizButton");
        startQuizButton->setMinimumSize(QSize(200, 50));
        startQuizButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #000000;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #000000;\n"
"}"));

        categoryNavLayout->addWidget(startQuizButton);


        verticalLayout_3->addLayout(categoryNavLayout);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        stackedWidget->addWidget(categoryPage);
        quizPage = new QWidget();
        quizPage->setObjectName("quizPage");
        verticalLayout_4 = new QVBoxLayout(quizPage);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(50, 30, 50, 30);
        quizHeaderLayout = new QHBoxLayout();
        quizHeaderLayout->setObjectName("quizHeaderLayout");
        questionNumberLabel = new QLabel(quizPage);
        questionNumberLabel->setObjectName("questionNumberLabel");
        questionNumberLabel->setStyleSheet(QString::fromUtf8("font-size: 16px; color: #7f8c8d;"));

        quizHeaderLayout->addWidget(questionNumberLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        quizHeaderLayout->addItem(horizontalSpacer_3);

        currentScoreLabel = new QLabel(quizPage);
        currentScoreLabel->setObjectName("currentScoreLabel");
        currentScoreLabel->setStyleSheet(QString::fromUtf8("font-size: 16px; font-weight: bold; color: #27ae60;"));

        quizHeaderLayout->addWidget(currentScoreLabel);

        categoryInfoLabel = new QLabel(quizPage);
        categoryInfoLabel->setObjectName("categoryInfoLabel");
        categoryInfoLabel->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #7f8c8d;"));

        quizHeaderLayout->addWidget(categoryInfoLabel);


        verticalLayout_4->addLayout(quizHeaderLayout);

        questionCard = new QFrame(quizPage);
        questionCard->setObjectName("questionCard");
        questionCard->setEnabled(true);
        questionCard->setMinimumSize(QSize(0, 500));
        verticalLayout_5 = new QVBoxLayout(questionCard);
        verticalLayout_5->setSpacing(30);
        verticalLayout_5->setObjectName("verticalLayout_5");
        questionLabel = new QLabel(questionCard);
        questionLabel->setObjectName("questionLabel");
        questionLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        questionLabel->setWordWrap(true);

        verticalLayout_5->addWidget(questionLabel);

        wordLabel = new QLabel(questionCard);
        wordLabel->setObjectName("wordLabel");
        wordLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(wordLabel);

        answersWidget = new QWidget(questionCard);
        answersWidget->setObjectName("answersWidget");
        answersWidget->setMinimumSize(QSize(0, 280));
        answersLayout = new QVBoxLayout(answersWidget);
        answersLayout->setSpacing(15);
        answersLayout->setObjectName("answersLayout");

        verticalLayout_5->addWidget(answersWidget);

        feedbackLabel = new QLabel(questionCard);
        feedbackLabel->setObjectName("feedbackLabel");
        feedbackLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        feedbackLabel->setWordWrap(true);

        verticalLayout_5->addWidget(feedbackLabel);


        verticalLayout_4->addWidget(questionCard);

        quizNavLayout = new QHBoxLayout();
        quizNavLayout->setObjectName("quizNavLayout");
        quitQuizButton = new QPushButton(quizPage);
        quitQuizButton->setObjectName("quitQuizButton");
        quitQuizButton->setMinimumSize(QSize(120, 45));
        quitQuizButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #e74c3c;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #c0392b;\n"
"}"));

        quizNavLayout->addWidget(quitQuizButton);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        quizNavLayout->addItem(horizontalSpacer_4);

        nextQuestionButton = new QPushButton(quizPage);
        nextQuestionButton->setObjectName("nextQuestionButton");
        nextQuestionButton->setMinimumSize(QSize(150, 45));
        nextQuestionButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        quizNavLayout->addWidget(nextQuestionButton);


        verticalLayout_4->addLayout(quizNavLayout);

        stackedWidget->addWidget(quizPage);
        resultsPage = new QWidget();
        resultsPage->setObjectName("resultsPage");
        verticalLayout_6 = new QVBoxLayout(resultsPage);
        verticalLayout_6->setSpacing(30);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(50, 40, 50, 40);
        resultsTitle = new QLabel(resultsPage);
        resultsTitle->setObjectName("resultsTitle");
        resultsTitle->setStyleSheet(QString::fromUtf8("font-size: 36px; font-weight: bold; color: #2c3e50;"));
        resultsTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(resultsTitle);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        resultsCard = new QFrame(resultsPage);
        resultsCard->setObjectName("resultsCard");
        resultsCard->setMinimumSize(QSize(0, 400));
        resultsCard->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: white;\n"
"    border-radius: 25px;\n"
"    padding: 50px;\n"
"    border: 3px solid #000000;\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(resultsCard);
        verticalLayout_7->setSpacing(25);
        verticalLayout_7->setObjectName("verticalLayout_7");
        scoreLabel = new QLabel(resultsCard);
        scoreLabel->setObjectName("scoreLabel");
        scoreLabel->setStyleSheet(QString::fromUtf8("font-size: 22px; color: #7f8c8d;"));
        scoreLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_7->addWidget(scoreLabel);

        resultLabel = new QLabel(resultsCard);
        resultLabel->setObjectName("resultLabel");
        resultLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_7->addWidget(resultLabel);

        percentageLabel = new QLabel(resultsCard);
        percentageLabel->setObjectName("percentageLabel");
        percentageLabel->setStyleSheet(QString::fromUtf8("font-size: 32px; font-weight: bold; color: #3498db;"));
        percentageLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_7->addWidget(percentageLabel);

        pointsLabel = new QLabel(resultsCard);
        pointsLabel->setObjectName("pointsLabel");
        pointsLabel->setStyleSheet(QString::fromUtf8("font-size: 24px; color: #f39c12;"));
        pointsLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_7->addWidget(pointsLabel);

        messageLabel = new QLabel(resultsCard);
        messageLabel->setObjectName("messageLabel");
        messageLabel->setStyleSheet(QString::fromUtf8("font-size: 20px; font-weight: bold; color: #27ae60;"));
        messageLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_7->addWidget(messageLabel);


        verticalLayout_6->addWidget(resultsCard);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_5);

        resultsButtonLayout = new QHBoxLayout();
        resultsButtonLayout->setObjectName("resultsButtonLayout");
        backToMenuButton = new QPushButton(resultsPage);
        backToMenuButton->setObjectName("backToMenuButton");
        backToMenuButton->setMinimumSize(QSize(180, 55));
        backToMenuButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        resultsButtonLayout->addWidget(backToMenuButton);

        restartSameButton = new QPushButton(resultsPage);
        restartSameButton->setObjectName("restartSameButton");
        restartSameButton->setMinimumSize(QSize(180, 55));
        restartSameButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #000000;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #000000;\n"
"}"));

        resultsButtonLayout->addWidget(restartSameButton);

        nextLevelButton = new QPushButton(resultsPage);
        nextLevelButton->setObjectName("nextLevelButton");
        nextLevelButton->setMinimumSize(QSize(180, 55));
        nextLevelButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #000000;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #000000;\n"
"}"));

        resultsButtonLayout->addWidget(nextLevelButton);


        verticalLayout_6->addLayout(resultsButtonLayout);

        stackedWidget->addWidget(resultsPage);
        statisticsPage = new QWidget();
        statisticsPage->setObjectName("statisticsPage");
        verticalLayout_8 = new QVBoxLayout(statisticsPage);
        verticalLayout_8->setSpacing(30);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(50, 40, 50, 40);
        statsPageTitle = new QLabel(statisticsPage);
        statsPageTitle->setObjectName("statsPageTitle");
        statsPageTitle->setStyleSheet(QString::fromUtf8("font-size: 32px; font-weight: bold; color: #2c3e50;"));
        statsPageTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_8->addWidget(statsPageTitle);

        statsGridLayout = new QGridLayout();
        statsGridLayout->setSpacing(20);
        statsGridLayout->setObjectName("statsGridLayout");
        statsCardHu = new QFrame(statisticsPage);
        statsCardHu->setObjectName("statsCardHu");
        statsCardHu->setMinimumSize(QSize(200, 150));
        verticalLayout_13 = new QVBoxLayout(statsCardHu);
        verticalLayout_13->setObjectName("verticalLayout_13");
        langIcon1 = new QLabel(statsCardHu);
        langIcon1->setObjectName("langIcon1");
        langIcon1->setStyleSheet(QString::fromUtf8("font-size: 40px;"));
        langIcon1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_13->addWidget(langIcon1);

        langName1 = new QLabel(statsCardHu);
        langName1->setObjectName("langName1");
        langName1->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold;"));
        langName1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_13->addWidget(langName1);

        langStats1 = new QLabel(statsCardHu);
        langStats1->setObjectName("langStats1");
        langStats1->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #7f8c8d;"));
        langStats1->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_13->addWidget(langStats1);


        statsGridLayout->addWidget(statsCardHu, 0, 0, 1, 1);

        statsCardEn = new QFrame(statisticsPage);
        statsCardEn->setObjectName("statsCardEn");
        statsCardEn->setMinimumSize(QSize(200, 150));
        verticalLayout_14 = new QVBoxLayout(statsCardEn);
        verticalLayout_14->setObjectName("verticalLayout_14");
        langIcon2 = new QLabel(statsCardEn);
        langIcon2->setObjectName("langIcon2");
        langIcon2->setStyleSheet(QString::fromUtf8("font-size: 40px;"));
        langIcon2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_14->addWidget(langIcon2);

        langName2 = new QLabel(statsCardEn);
        langName2->setObjectName("langName2");
        langName2->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold;"));
        langName2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_14->addWidget(langName2);

        langStats2 = new QLabel(statsCardEn);
        langStats2->setObjectName("langStats2");
        langStats2->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #7f8c8d;"));
        langStats2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_14->addWidget(langStats2);


        statsGridLayout->addWidget(statsCardEn, 0, 1, 1, 1);

        statsCardDe = new QFrame(statisticsPage);
        statsCardDe->setObjectName("statsCardDe");
        statsCardDe->setMinimumSize(QSize(200, 150));
        verticalLayout_15 = new QVBoxLayout(statsCardDe);
        verticalLayout_15->setObjectName("verticalLayout_15");
        langIcon3 = new QLabel(statsCardDe);
        langIcon3->setObjectName("langIcon3");
        langIcon3->setStyleSheet(QString::fromUtf8("font-size: 40px;"));
        langIcon3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_15->addWidget(langIcon3);

        langName3 = new QLabel(statsCardDe);
        langName3->setObjectName("langName3");
        langName3->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold;"));
        langName3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_15->addWidget(langName3);

        langStats3 = new QLabel(statsCardDe);
        langStats3->setObjectName("langStats3");
        langStats3->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #7f8c8d;"));
        langStats3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_15->addWidget(langStats3);


        statsGridLayout->addWidget(statsCardDe, 1, 0, 1, 1);

        statsCardRu = new QFrame(statisticsPage);
        statsCardRu->setObjectName("statsCardRu");
        statsCardRu->setMinimumSize(QSize(200, 150));
        verticalLayout_16 = new QVBoxLayout(statsCardRu);
        verticalLayout_16->setObjectName("verticalLayout_16");
        langIcon4 = new QLabel(statsCardRu);
        langIcon4->setObjectName("langIcon4");
        langIcon4->setStyleSheet(QString::fromUtf8("font-size: 40px;"));
        langIcon4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_16->addWidget(langIcon4);

        langName4 = new QLabel(statsCardRu);
        langName4->setObjectName("langName4");
        langName4->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold;"));
        langName4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_16->addWidget(langName4);

        langStats4 = new QLabel(statsCardRu);
        langStats4->setObjectName("langStats4");
        langStats4->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #7f8c8d;"));
        langStats4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_16->addWidget(langStats4);


        statsGridLayout->addWidget(statsCardRu, 1, 1, 1, 1);


        verticalLayout_8->addLayout(statsGridLayout);

        backFromStatsButton = new QPushButton(statisticsPage);
        backFromStatsButton->setObjectName("backFromStatsButton");
        backFromStatsButton->setMinimumSize(QSize(200, 50));
        backFromStatsButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        verticalLayout_8->addWidget(backFromStatsButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_6);

        stackedWidget->addWidget(statisticsPage);

        horizontalLayout->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Agytorna - Nyelvtanul\303\263 Kv\303\255z", nullptr));
        homeButton->setText(QString());
        languagesButton->setText(QString());
        profileButton->setText(QString());
        statsButton->setText(QString());
        logoutButton->setText(QString());
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "\303\234dv\303\266z\303\266l az Agytorna! \360\237\247\240", nullptr));
        subtitleLabel->setText(QCoreApplication::translate("MainWindow", "V\303\241lassz nyelvet \303\251s kezdj el tanulni!", nullptr));
        statsIcon1->setText(QCoreApplication::translate("MainWindow", "\360\237\216\257", nullptr));
        completedLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        completedText->setText(QCoreApplication::translate("MainWindow", "Teljes\303\255tett kv\303\255z", nullptr));
        statsIcon2->setText(QCoreApplication::translate("MainWindow", "\360\237\223\232", nullptr));
        wordsLearnedLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        wordsLearnedText->setText(QCoreApplication::translate("MainWindow", "Megtanult sz\303\263", nullptr));
        statsIcon3->setText(QCoreApplication::translate("MainWindow", "\360\237\224\245", nullptr));
        streakLabel->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        streakText->setText(QCoreApplication::translate("MainWindow", "Napos sorozat", nullptr));
        sectionLabel->setText(QCoreApplication::translate("MainWindow", "V\303\241lassz nyelvet \360\237\214\215", nullptr));
        hungarianButton->setText(QCoreApplication::translate("MainWindow", "\360\237\207\255\360\237\207\272 Magyar", nullptr));
        englishButton->setText(QCoreApplication::translate("MainWindow", "\360\237\207\254\360\237\207\247 English", nullptr));
        germanButton->setText(QCoreApplication::translate("MainWindow", "\360\237\207\251\360\237\207\252 Deutsch", nullptr));
        russianButton->setText(QCoreApplication::translate("MainWindow", "\360\237\207\267\360\237\207\272 \320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        categoryTitle->setText(QCoreApplication::translate("MainWindow", "V\303\241lassz kateg\303\263ri\303\241t \360\237\223\232", nullptr));
        selectedLanguageLabel->setText(QCoreApplication::translate("MainWindow", "Kiv\303\241lasztott nyelv: Magyar \360\237\207\255\360\237\207\272", nullptr));
        vocabularyButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\226 Sz\303\263kincs", nullptr));
        grammarButton->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217 Nyelvtan", nullptr));
        sentencesButton->setText(QCoreApplication::translate("MainWindow", "\360\237\222\254 Mondatok", nullptr));
        listeningButton->setText(QCoreApplication::translate("MainWindow", "\360\237\216\247 Hall\303\241s ut\303\241ni", nullptr));
        difficultyTitle->setText(QCoreApplication::translate("MainWindow", "V\303\241lassz neh\303\251zs\303\251gi szintet \360\237\216\257", nullptr));
        beginnerButton->setText(QCoreApplication::translate("MainWindow", "\360\237\214\261 Kezd\305\221", nullptr));
        intermediateButton->setText(QCoreApplication::translate("MainWindow", "\342\255\220 Halad\303\263", nullptr));
        advancedButton->setText(QCoreApplication::translate("MainWindow", "\360\237\217\206 Profi", nullptr));
        backFromCategoryButton->setText(QCoreApplication::translate("MainWindow", "\342\254\205 Vissza", nullptr));
        startQuizButton->setText(QCoreApplication::translate("MainWindow", "Kv\303\255z ind\303\255t\303\241sa! \360\237\232\200", nullptr));
        questionNumberLabel->setText(QCoreApplication::translate("MainWindow", "K\303\251rd\303\251s 1/10", nullptr));
        currentScoreLabel->setText(QCoreApplication::translate("MainWindow", "Pontsz\303\241m: 0", nullptr));
        categoryInfoLabel->setText(QCoreApplication::translate("MainWindow", "\360\237\223\226 Sz\303\263kincs | \360\237\214\261 Kezd\305\221", nullptr));
        questionLabel->setText(QCoreApplication::translate("MainWindow", "Mit jelent ez a sz\303\263 magyarul?", nullptr));
        wordLabel->setText(QCoreApplication::translate("MainWindow", "apple", nullptr));
        feedbackLabel->setText(QString());
        quitQuizButton->setText(QCoreApplication::translate("MainWindow", "\342\235\214 Kil\303\251p\303\251s", nullptr));
        nextQuestionButton->setText(QCoreApplication::translate("MainWindow", "K\303\266vetkez\305\221 \342\236\241", nullptr));
        resultsTitle->setText(QCoreApplication::translate("MainWindow", "\360\237\216\211 Kv\303\255z Befejezve!", nullptr));
        scoreLabel->setText(QCoreApplication::translate("MainWindow", "A te eredm\303\251nyed:", nullptr));
        resultLabel->setText(QCoreApplication::translate("MainWindow", "8 / 10", nullptr));
        percentageLabel->setText(QCoreApplication::translate("MainWindow", "80%", nullptr));
        pointsLabel->setText(QCoreApplication::translate("MainWindow", "Pontsz\303\241m: 80", nullptr));
        messageLabel->setText(QCoreApplication::translate("MainWindow", "Nagyszer\305\261 munka! \360\237\221\217", nullptr));
        backToMenuButton->setText(QCoreApplication::translate("MainWindow", "\360\237\217\240 F\305\221men\303\274", nullptr));
        restartSameButton->setText(QCoreApplication::translate("MainWindow", "\360\237\224\204 \303\232jra", nullptr));
        nextLevelButton->setText(QCoreApplication::translate("MainWindow", "\342\254\206 Nehezebb", nullptr));
        statsPageTitle->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 Statisztik\303\241id", nullptr));
        langIcon1->setText(QCoreApplication::translate("MainWindow", "\360\237\207\255\360\237\207\272", nullptr));
        langName1->setText(QCoreApplication::translate("MainWindow", "Magyar", nullptr));
        langStats1->setText(QCoreApplication::translate("MainWindow", "25 sz\303\263 | 85%", nullptr));
        langIcon2->setText(QCoreApplication::translate("MainWindow", "\360\237\207\254\360\237\207\247", nullptr));
        langName2->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
        langStats2->setText(QCoreApplication::translate("MainWindow", "42 sz\303\263 | 92%", nullptr));
        langIcon3->setText(QCoreApplication::translate("MainWindow", "\360\237\207\251\360\237\207\252", nullptr));
        langName3->setText(QCoreApplication::translate("MainWindow", "Deutsch", nullptr));
        langStats3->setText(QCoreApplication::translate("MainWindow", "18 sz\303\263 | 78%", nullptr));
        langIcon4->setText(QCoreApplication::translate("MainWindow", "\360\237\207\267\360\237\207\272", nullptr));
        langName4->setText(QCoreApplication::translate("MainWindow", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        langStats4->setText(QCoreApplication::translate("MainWindow", "12 sz\303\263 | 70%", nullptr));
        backFromStatsButton->setText(QCoreApplication::translate("MainWindow", "\342\254\205 Vissza a f\305\221men\303\274be", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
