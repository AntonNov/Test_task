#include "mainwindow.h"

#include <QGroupBox>
#include <QListView>
#include <QTableView>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>

#include "GraphicsCanvasView.h"
#include "IconListWidget.h"
#include "IconDocument.h"
#include "iconpainter.h"


const int CANVAS_WIDTH = 1024;
const int CANVAS_HEIGHT = 512;
const int CONTROL_WIDTH = 300;
const int LAYOUT_MARGIN = 8;
const int LAYOUT_SPACING = 8;
const int MIN_PANEL_HEIGHT = 200;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_canvasView(nullptr),
    m_iconList(nullptr),
    m_controlsGroup(nullptr),
    m_recordsView(nullptr),
    m_coordinatesView(nullptr)
{
    setupUi();
    setupConnections();
}

MainWindow::~MainWindow() = default;

void MainWindow::setupUi()
{
    setWindowTitle("MainForm");
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    m_canvasView = new GraphicsCanvasView(centralWidget);
    m_canvasView->setFixedSize(CANVAS_WIDTH, CANVAS_HEIGHT);

    m_iconList = new IconListWidget(centralWidget);
    m_iconList->setIconSize(QSize(64, 64));
    m_iconList->addIcon(icon(InfoIcon), "Иконка", InfoIcon);
    m_iconList->setCurrentRow(0);

    m_controlsGroup = new QGroupBox("Элементы управления", centralWidget);
    m_controlsGroup->setFixedWidth(CONTROL_WIDTH);

    QVBoxLayout *controlsLayout = new QVBoxLayout(m_controlsGroup);
    controlsLayout->setContentsMargins(LAYOUT_MARGIN, LAYOUT_MARGIN, LAYOUT_MARGIN, LAYOUT_MARGIN);
    controlsLayout->addWidget(m_iconList);

    m_recordsView = new QListView(centralWidget);
    m_recordsView->setObjectName("recordsView");
    m_recordsView->setSelectionMode(QAbstractItemView::SingleSelection);
    m_recordsView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_recordsView->setUniformItemSizes(true);


    m_coordinatesView = new QTableView(centralWidget);
    m_coordinatesView->setObjectName("coordinatesView");
    m_coordinatesView->setMinimumHeight(MIN_PANEL_HEIGHT);
    m_coordinatesView->setSelectionMode(QAbstractItemView::SingleSelection);
    m_coordinatesView->setSelectionBehavior(QAbstractItemView::SelectItems);
    m_coordinatesView->setEditTriggers(QAbstractItemView::DoubleClicked
                                       | QAbstractItemView::EditKeyPressed
                                       | QAbstractItemView::AnyKeyPressed);

    QHBoxLayout *bottomRow = new QHBoxLayout;
    bottomRow->setSpacing(LAYOUT_SPACING);
    bottomRow->addWidget(m_recordsView);
    bottomRow->addWidget(m_coordinatesView);

    QVBoxLayout *leftColumn = new QVBoxLayout;
    leftColumn->setSpacing(LAYOUT_SPACING);
    leftColumn->addWidget(m_canvasView, 0, Qt::AlignLeft | Qt::AlignTop);
    leftColumn->addLayout(bottomRow, 1);

    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);
    mainLayout->setContentsMargins(LAYOUT_MARGIN, LAYOUT_MARGIN, LAYOUT_MARGIN, LAYOUT_MARGIN);
    mainLayout->setSpacing(LAYOUT_SPACING);
    mainLayout->addLayout(leftColumn, 1);
    mainLayout->addWidget(m_controlsGroup, 0);

}


void MainWindow::setupConnections()
{


}

