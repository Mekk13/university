#include "Researcher_Window.h"
#include <QMessageBox>
#include <QVBoxLayout>

Researcher_Window::Researcher_Window(Service& serv, TableModel* model, const std::string& name, const std::string& pos, QWidget* parent)
	: QWidget(parent), serv(serv), model(model), name(name), pos(pos)
{
    ui.setupUi(this);

	//ion want the butto for everyon
	if (pos == "senior") {
		ui.seniorButton->show();
	}
	else {
		ui.seniorButton->hide();
	}
	if (serv.hasAccepted(name)) {
		ui.developButton->show();
	}
	else {
		ui.developButton->hide();
	}

    ui.tableView->setModel(model);
   
    model->setitems(serv.getIdeas());
	connect(ui.addButton, &QPushButton::clicked, this, &Researcher_Window::onAddPushed);
	connect(ui.acceptButton, &QPushButton::clicked, this, &Researcher_Window::onAcceptPushed);
	connect(ui.seniorButton, &QPushButton::clicked, this, &Researcher_Window::onSavePushed);
	connect(ui.developButton, &QPushButton::clicked, this, &Researcher_Window::onDevelopPushed);
	ui.position_edit->setText(QString::fromStdString(pos));
    this->setWindowTitle(QString::fromStdString(name));
    populateTable();
}

Researcher_Window::~Researcher_Window()
{

}

void Researcher_Window::onAddPushed()
{
    //we wanna add the idea from the lineedits titleEdit, DescrEdit and DurationEdit
	QString title = ui.titleEdit->text();
	QString description = ui.descrEdit->text();
	QString status = "Proposed"; 
	int duration = ui.DurationEdit->text().toInt();

    //show a message box and stop if the title is empty and the duration is not 1 2 3 
    //and also the creator is the current windowresearcher
	if (title.isEmpty() || duration < 1 || duration > 3) {
		QMessageBox::warning(this, "Error", "Please enter a valid title and duration (1-3).");
		return;
	}
	
	Idea idea(title.toStdString(), description.toStdString(), status.toStdString(), name, duration);
	serv.addIdea(idea);
	model->addItem(idea);

}

void Researcher_Window::onAcceptPushed()
{
	//here we want to accept ideas that are proposed but only senior researchers can accept ideas
	//we have position as pos so pos!=senior
	if (pos.compare("senior")!=0) {
		QMessageBox::warning(this, "Error", "Only Senior Researchers can accept ideas.");
		return;
	}
	
	QModelIndexList selectedIndexes = ui.tableView->selectionModel()->selectedRows();
	if (selectedIndexes.isEmpty()) {
		QMessageBox::warning(this, "Error", "Please select an idea to accept.");
		return;
	}
	
	QModelIndex index = selectedIndexes.first();
	
	Idea idea = model->getItem(index.row());
	
	if (idea.getStatus() == "Accepted") {
		QMessageBox::warning(this, "Error", "This idea is already accepted.");
		return;
	}
	
	idea.setStatus("Accepted");
	
	serv.acceptIdea(idea);
	
	model->setitems(serv.getIdeas());
	QMessageBox::information(this, "Success", "Idea accepted successfully.");
}

void Researcher_Window::onSavePushed()
{
	//here we wanna save the accepted ideas in a file
	serv.save_accepted_ideas();
	
	QMessageBox::information(this, "Success", "Ideas saved successfully.");

}
void Researcher_Window::onDevelopPushed()
{
	vector<Idea> accepted_ideas = serv.getAcceptedFrom(name);

	for (auto& idea : accepted_ideas) {
		QWidget* developWindow = new QWidget();
		developWindow->setWindowTitle(QString::fromStdString(idea.getTitle()));
		QVBoxLayout* layout = new QVBoxLayout(developWindow);

		QLineEdit* descriptionEdit = new QLineEdit(QString::fromStdString(idea.getDescription()));
		layout->addWidget(descriptionEdit);

		QPushButton* saveButton = new QPushButton("Save");
		layout->addWidget(saveButton); 

		
		developWindow->setLayout(layout);
		developWindow->show();

		connect(saveButton, &QPushButton::clicked, [this, idea, descriptionEdit, developWindow]() {
			Idea updatedIdea = idea;
			updatedIdea.setDescription(descriptionEdit->text().toStdString());
			serv.updateIdea(idea, updatedIdea);
			model->setitems(serv.getIdeas());
			serv.save_an_idea_PLS(updatedIdea);
			QMessageBox::information(this, "Success", "Idea updatedd.");
			developWindow->close();
			});
	}
}

void Researcher_Window::populateTable()
{
    ui.tableView->resizeColumnsToContents();
}
