#pragma once
#include "SnakeGame.h"

namespace SE2730FINALLEA {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	static const int PANEL_POS;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			game = nullptr;
			direction = 'd';
			direction2 = 'l';
			gameType = 'N';
			menuPanel->Location = Point(PANEL_POS, PANEL_POS);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private:SnakeGame* game;
	private:char direction;
	private:char direction2;
	private: char gameType; //C = classic, B = MysteryBox, M = Multiplayer
	private: System::Windows::Forms::Button^ gamemodeBtn;
	protected:

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ menuPanel;

	private: System::Windows::Forms::Button^ helpBtn;
	private: System::Windows::Forms::Button^ highscoreBtn;
	private: System::Windows::Forms::Panel^ gamemodePanel;

	private: System::Windows::Forms::Button^ classicBtn;
	private: System::Windows::Forms::Button^ mysteryBtn;
	private: System::Windows::Forms::Button^ multiBtn;
	private: System::Windows::Forms::Button^ gamemodereturnBtn;
	private: System::Windows::Forms::Panel^ highscorePanel;
	private: System::Windows::Forms::Button^ highscorereturnBtn;
	private: System::Windows::Forms::Panel^ helpPanel;
	private: System::Windows::Forms::Button^ helpreturnBtn;
	private: System::Windows::Forms::Panel^ gamePanel;
	private: System::Windows::Forms::Timer^ gameTimer;
	private: System::Windows::Forms::RichTextBox^ ScoreTextBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ helpLabel;
	private: System::Windows::Forms::Label^ highScoreLabel;
	private: System::Windows::Forms::Panel^ p1Panel;
	private: System::Windows::Forms::Panel^ p2Panel;
	private: System::Windows::Forms::Panel^ mGameOverPanel;
	private: System::Windows::Forms::Label^ winningScore;
	private: System::Windows::Forms::Label^ winnerLabel;
	private: System::Windows::Forms::Label^ winnerText;
	private: System::Windows::Forms::Button^ toMainMenu;

	private: System::Windows::Forms::Label^ p2Label;








	private: System::Windows::Forms::Label^ p1Label;
	private: System::Windows::Forms::RichTextBox^ p1Score;
	private: System::Windows::Forms::RichTextBox^ p2Score;
	private: System::Windows::Forms::RichTextBox^ boxReward;
	private: System::Windows::Forms::Label^ mysteryLabel;









	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->gamemodeBtn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuPanel = (gcnew System::Windows::Forms::Panel());
			this->helpBtn = (gcnew System::Windows::Forms::Button());
			this->highscoreBtn = (gcnew System::Windows::Forms::Button());
			this->gamemodePanel = (gcnew System::Windows::Forms::Panel());
			this->gamemodereturnBtn = (gcnew System::Windows::Forms::Button());
			this->mysteryBtn = (gcnew System::Windows::Forms::Button());
			this->multiBtn = (gcnew System::Windows::Forms::Button());
			this->classicBtn = (gcnew System::Windows::Forms::Button());
			this->gamePanel = (gcnew System::Windows::Forms::Panel());
			this->ScoreTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->highscorePanel = (gcnew System::Windows::Forms::Panel());
			this->highScoreLabel = (gcnew System::Windows::Forms::Label());
			this->highscorereturnBtn = (gcnew System::Windows::Forms::Button());
			this->helpPanel = (gcnew System::Windows::Forms::Panel());
			this->helpLabel = (gcnew System::Windows::Forms::Label());
			this->helpreturnBtn = (gcnew System::Windows::Forms::Button());
			this->gameTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->p1Panel = (gcnew System::Windows::Forms::Panel());
			this->p1Score = (gcnew System::Windows::Forms::RichTextBox());
			this->p1Label = (gcnew System::Windows::Forms::Label());
			this->p2Panel = (gcnew System::Windows::Forms::Panel());
			this->p2Score = (gcnew System::Windows::Forms::RichTextBox());
			this->p2Label = (gcnew System::Windows::Forms::Label());
			this->mGameOverPanel = (gcnew System::Windows::Forms::Panel());
			this->winningScore = (gcnew System::Windows::Forms::Label());
			this->winnerLabel = (gcnew System::Windows::Forms::Label());
			this->winnerText = (gcnew System::Windows::Forms::Label());
			this->toMainMenu = (gcnew System::Windows::Forms::Button());
			this->mysteryLabel = (gcnew System::Windows::Forms::Label());
			this->boxReward = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuPanel->SuspendLayout();
			this->gamemodePanel->SuspendLayout();
			this->gamePanel->SuspendLayout();
			this->highscorePanel->SuspendLayout();
			this->helpPanel->SuspendLayout();
			this->p1Panel->SuspendLayout();
			this->p2Panel->SuspendLayout();
			this->mGameOverPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// gamemodeBtn
			// 
			this->gamemodeBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->gamemodeBtn->ForeColor = System::Drawing::SystemColors::Desktop;
			this->gamemodeBtn->Location = System::Drawing::Point(471, 151);
			this->gamemodeBtn->Name = L"gamemodeBtn";
			this->gamemodeBtn->Size = System::Drawing::Size(250, 65);
			this->gamemodeBtn->TabIndex = 0;
			this->gamemodeBtn->Text = L"Start";
			this->gamemodeBtn->UseVisualStyleBackColor = true;
			this->gamemodeBtn->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::gamemodeBtn_MouseDown);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(462, 9);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(275, 101);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// menuPanel
			// 
			this->menuPanel->Controls->Add(this->helpBtn);
			this->menuPanel->Controls->Add(this->highscoreBtn);
			this->menuPanel->Controls->Add(this->gamemodeBtn);
			this->menuPanel->Controls->Add(this->pictureBox1);
			this->menuPanel->Location = System::Drawing::Point(39, 113);
			this->menuPanel->Name = L"menuPanel";
			this->menuPanel->Size = System::Drawing::Size(1232, 666);
			this->menuPanel->TabIndex = 3;
			// 
			// helpBtn
			// 
			this->helpBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->helpBtn->Location = System::Drawing::Point(471, 375);
			this->helpBtn->Name = L"helpBtn";
			this->helpBtn->Size = System::Drawing::Size(250, 65);
			this->helpBtn->TabIndex = 4;
			this->helpBtn->Text = L"Help";
			this->helpBtn->UseVisualStyleBackColor = true;
			this->helpBtn->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::helpBtn_MouseDown);
			// 
			// highscoreBtn
			// 
			this->highscoreBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->highscoreBtn->Location = System::Drawing::Point(471, 260);
			this->highscoreBtn->Name = L"highscoreBtn";
			this->highscoreBtn->Size = System::Drawing::Size(250, 65);
			this->highscoreBtn->TabIndex = 3;
			this->highscoreBtn->Text = L"High Scores";
			this->highscoreBtn->UseVisualStyleBackColor = true;
			this->highscoreBtn->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::highscoreBtn_MouseDown);
			// 
			// gamemodePanel
			// 
			this->gamemodePanel->Controls->Add(this->gamemodereturnBtn);
			this->gamemodePanel->Controls->Add(this->mysteryBtn);
			this->gamemodePanel->Controls->Add(this->multiBtn);
			this->gamemodePanel->Controls->Add(this->classicBtn);
			this->gamemodePanel->Enabled = false;
			this->gamemodePanel->Location = System::Drawing::Point(82, 59);
			this->gamemodePanel->Name = L"gamemodePanel";
			this->gamemodePanel->Size = System::Drawing::Size(1232, 666);
			this->gamemodePanel->TabIndex = 5;
			this->gamemodePanel->Visible = false;
			// 
			// gamemodereturnBtn
			// 
			this->gamemodereturnBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->gamemodereturnBtn->Location = System::Drawing::Point(27, 22);
			this->gamemodereturnBtn->Name = L"gamemodereturnBtn";
			this->gamemodereturnBtn->Size = System::Drawing::Size(75, 23);
			this->gamemodereturnBtn->TabIndex = 3;
			this->gamemodereturnBtn->Text = L"Back";
			this->gamemodereturnBtn->UseVisualStyleBackColor = true;
			this->gamemodereturnBtn->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::gamemodereturnBtn_MouseDown);
			// 
			// mysteryBtn
			// 
			this->mysteryBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->mysteryBtn->Location = System::Drawing::Point(492, 376);
			this->mysteryBtn->Name = L"mysteryBtn";
			this->mysteryBtn->Size = System::Drawing::Size(250, 65);
			this->mysteryBtn->TabIndex = 2;
			this->mysteryBtn->Text = L"\?Mystery\?";
			this->mysteryBtn->UseVisualStyleBackColor = true;
			this->mysteryBtn->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::mysteryBtn_MouseDown);
			// 
			// multiBtn
			// 
			this->multiBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->multiBtn->Location = System::Drawing::Point(492, 256);
			this->multiBtn->Margin = System::Windows::Forms::Padding(2);
			this->multiBtn->Name = L"multiBtn";
			this->multiBtn->Size = System::Drawing::Size(250, 67);
			this->multiBtn->TabIndex = 1;
			this->multiBtn->Text = L"Multiplayer";
			this->multiBtn->UseVisualStyleBackColor = true;
			this->multiBtn->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::multiBtn_MouseDown);
			// 
			// classicBtn
			// 
			this->classicBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->classicBtn->Location = System::Drawing::Point(492, 141);
			this->classicBtn->Name = L"classicBtn";
			this->classicBtn->Size = System::Drawing::Size(250, 65);
			this->classicBtn->TabIndex = 0;
			this->classicBtn->Text = L"Classic";
			this->classicBtn->UseVisualStyleBackColor = true;
			this->classicBtn->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::classicBtn_MouseDown);
			// 
			// gamePanel
			// 
			this->gamePanel->Controls->Add(this->boxReward);
			this->gamePanel->Controls->Add(this->mysteryLabel);
			this->gamePanel->Controls->Add(this->ScoreTextBox);
			this->gamePanel->Controls->Add(this->label1);
			this->gamePanel->Enabled = false;
			this->gamePanel->Location = System::Drawing::Point(36, 12);
			this->gamePanel->Name = L"gamePanel";
			this->gamePanel->Size = System::Drawing::Size(1232, 666);
			this->gamePanel->TabIndex = 8;
			this->gamePanel->Visible = false;
			// 
			// ScoreTextBox
			// 
			this->ScoreTextBox->Location = System::Drawing::Point(1154, 16);
			this->ScoreTextBox->Margin = System::Windows::Forms::Padding(2);
			this->ScoreTextBox->Name = L"ScoreTextBox";
			this->ScoreTextBox->ReadOnly = true;
			this->ScoreTextBox->Size = System::Drawing::Size(65, 23);
			this->ScoreTextBox->TabIndex = 1;
			this->ScoreTextBox->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1115, 19);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Score";
			// 
			// highscorePanel
			// 
			this->highscorePanel->Controls->Add(this->highScoreLabel);
			this->highscorePanel->Controls->Add(this->highscorereturnBtn);
			this->highscorePanel->Enabled = false;
			this->highscorePanel->Location = System::Drawing::Point(26, 136);
			this->highscorePanel->Name = L"highscorePanel";
			this->highscorePanel->Size = System::Drawing::Size(1232, 666);
			this->highscorePanel->TabIndex = 6;
			this->highscorePanel->Visible = false;
			// 
			// highScoreLabel
			// 
			this->highScoreLabel->AutoSize = true;
			this->highScoreLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->highScoreLabel->Location = System::Drawing::Point(476, 262);
			this->highScoreLabel->Name = L"highScoreLabel";
			this->highScoreLabel->Size = System::Drawing::Size(70, 25);
			this->highScoreLabel->TabIndex = 1;
			this->highScoreLabel->Text = L"label2";
			// 
			// highscorereturnBtn
			// 
			this->highscorereturnBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->highscorereturnBtn->Location = System::Drawing::Point(27, 19);
			this->highscorereturnBtn->Name = L"highscorereturnBtn";
			this->highscorereturnBtn->Size = System::Drawing::Size(75, 23);
			this->highscorereturnBtn->TabIndex = 0;
			this->highscorereturnBtn->Text = L"Back";
			this->highscorereturnBtn->UseVisualStyleBackColor = true;
			this->highscorereturnBtn->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::highscorereturnBtn_MouseDown);
			// 
			// helpPanel
			// 
			this->helpPanel->Controls->Add(this->helpLabel);
			this->helpPanel->Controls->Add(this->helpreturnBtn);
			this->helpPanel->Enabled = false;
			this->helpPanel->Location = System::Drawing::Point(70, 73);
			this->helpPanel->Name = L"helpPanel";
			this->helpPanel->Size = System::Drawing::Size(1232, 666);
			this->helpPanel->TabIndex = 7;
			this->helpPanel->Visible = false;
			// 
			// helpLabel
			// 
			this->helpLabel->AutoSize = true;
			this->helpLabel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->helpLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->helpLabel->ForeColor = System::Drawing::SystemColors::ControlText;
			this->helpLabel->Location = System::Drawing::Point(223, 215);
			this->helpLabel->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->helpLabel->Name = L"helpLabel";
			this->helpLabel->Size = System::Drawing::Size(740, 155);
			this->helpLabel->TabIndex = 1;
			this->helpLabel->Text = resources->GetString(L"helpLabel.Text");
			// 
			// helpreturnBtn
			// 
			this->helpreturnBtn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->helpreturnBtn->Location = System::Drawing::Point(27, 19);
			this->helpreturnBtn->Name = L"helpreturnBtn";
			this->helpreturnBtn->Size = System::Drawing::Size(75, 23);
			this->helpreturnBtn->TabIndex = 0;
			this->helpreturnBtn->Text = L"Back";
			this->helpreturnBtn->UseVisualStyleBackColor = true;
			this->helpreturnBtn->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::helpreturnBtn_MouseDown);
			// 
			// gameTimer
			// 
			this->gameTimer->Interval = 200;
			this->gameTimer->Tick += gcnew System::EventHandler(this, &MyForm::gameTimer_Tick);
			// 
			// p1Panel
			// 
			this->p1Panel->Controls->Add(this->p1Score);
			this->p1Panel->Controls->Add(this->p1Label);
			this->p1Panel->Enabled = false;
			this->p1Panel->Location = System::Drawing::Point(144, 31);
			this->p1Panel->Name = L"p1Panel";
			this->p1Panel->Size = System::Drawing::Size(616, 666);
			this->p1Panel->TabIndex = 9;
			this->p1Panel->Visible = false;
			// 
			// p1Score
			// 
			this->p1Score->Location = System::Drawing::Point(550, 44);
			this->p1Score->Name = L"p1Score";
			this->p1Score->Size = System::Drawing::Size(52, 18);
			this->p1Score->TabIndex = 5;
			this->p1Score->Text = L"";
			// 
			// p1Label
			// 
			this->p1Label->AutoSize = true;
			this->p1Label->Location = System::Drawing::Point(558, 28);
			this->p1Label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->p1Label->Name = L"p1Label";
			this->p1Label->Size = System::Drawing::Size(35, 13);
			this->p1Label->TabIndex = 4;
			this->p1Label->Text = L"Score";
			// 
			// p2Panel
			// 
			this->p2Panel->Controls->Add(this->p2Score);
			this->p2Panel->Controls->Add(this->p2Label);
			this->p2Panel->Enabled = false;
			this->p2Panel->Location = System::Drawing::Point(1, 70);
			this->p2Panel->Name = L"p2Panel";
			this->p2Panel->Size = System::Drawing::Size(616, 666);
			this->p2Panel->TabIndex = 10;
			this->p2Panel->Visible = false;
			// 
			// p2Score
			// 
			this->p2Score->Location = System::Drawing::Point(546, 40);
			this->p2Score->Name = L"p2Score";
			this->p2Score->Size = System::Drawing::Size(57, 22);
			this->p2Score->TabIndex = 3;
			this->p2Score->Text = L"";
			// 
			// p2Label
			// 
			this->p2Label->AutoSize = true;
			this->p2Label->Location = System::Drawing::Point(559, 24);
			this->p2Label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->p2Label->Name = L"p2Label";
			this->p2Label->Size = System::Drawing::Size(35, 13);
			this->p2Label->TabIndex = 2;
			this->p2Label->Text = L"Score";
			// 
			// mGameOverPanel
			// 
			this->mGameOverPanel->Controls->Add(this->winningScore);
			this->mGameOverPanel->Controls->Add(this->winnerLabel);
			this->mGameOverPanel->Controls->Add(this->winnerText);
			this->mGameOverPanel->Controls->Add(this->toMainMenu);
			this->mGameOverPanel->Enabled = false;
			this->mGameOverPanel->Location = System::Drawing::Point(15, 15);
			this->mGameOverPanel->Name = L"mGameOverPanel";
			this->mGameOverPanel->Size = System::Drawing::Size(1232, 666);
			this->mGameOverPanel->TabIndex = 11;
			this->mGameOverPanel->Visible = false;
			// 
			// winningScore
			// 
			this->winningScore->AutoSize = true;
			this->winningScore->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->winningScore->Location = System::Drawing::Point(608, 230);
			this->winningScore->Name = L"winningScore";
			this->winningScore->Size = System::Drawing::Size(0, 20);
			this->winningScore->TabIndex = 3;
			// 
			// winnerLabel
			// 
			this->winnerLabel->AutoSize = true;
			this->winnerLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->winnerLabel->Location = System::Drawing::Point(541, 171);
			this->winnerLabel->Name = L"winnerLabel";
			this->winnerLabel->Size = System::Drawing::Size(0, 37);
			this->winnerLabel->TabIndex = 2;
			// 
			// winnerText
			// 
			this->winnerText->AutoSize = true;
			this->winnerText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->winnerText->Location = System::Drawing::Point(522, 95);
			this->winnerText->Name = L"winnerText";
			this->winnerText->Size = System::Drawing::Size(182, 55);
			this->winnerText->TabIndex = 1;
			this->winnerText->Text = L"Winner";
			// 
			// toMainMenu
			// 
			this->toMainMenu->Location = System::Drawing::Point(24, 17);
			this->toMainMenu->Name = L"toMainMenu";
			this->toMainMenu->Size = System::Drawing::Size(75, 23);
			this->toMainMenu->TabIndex = 0;
			this->toMainMenu->Text = L"Main Menu";
			this->toMainMenu->UseVisualStyleBackColor = true;
			this->toMainMenu->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::toMainMenu_MouseDown);
			// 
			// mysteryLabel
			// 
			this->mysteryLabel->AutoSize = true;
			this->mysteryLabel->Enabled = false;
			this->mysteryLabel->Location = System::Drawing::Point(1133, 45);
			this->mysteryLabel->Name = L"mysteryLabel";
			this->mysteryLabel->Size = System::Drawing::Size(64, 13);
			this->mysteryLabel->TabIndex = 2;
			this->mysteryLabel->Text = L"Mystery Box";
			this->mysteryLabel->Visible = false;
			// 
			// boxReward
			// 
			this->boxReward->Enabled = false;
			this->boxReward->Location = System::Drawing::Point(1118, 61);
			this->boxReward->Name = L"boxReward";
			this->boxReward->Size = System::Drawing::Size(100, 20);
			this->boxReward->TabIndex = 3;
			this->boxReward->Text = L"";
			this->boxReward->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1253, 690);
			this->Controls->Add(this->gamePanel);
			this->Controls->Add(this->p2Panel);
			this->Controls->Add(this->p1Panel);
			this->Controls->Add(this->highscorePanel);
			this->Controls->Add(this->menuPanel);
			this->Controls->Add(this->helpPanel);
			this->Controls->Add(this->gamemodePanel);
			this->Controls->Add(this->mGameOverPanel);
			this->DoubleBuffered = true;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::MyForm_KeyPress);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuPanel->ResumeLayout(false);
			this->gamemodePanel->ResumeLayout(false);
			this->gamePanel->ResumeLayout(false);
			this->gamePanel->PerformLayout();
			this->highscorePanel->ResumeLayout(false);
			this->highscorePanel->PerformLayout();
			this->helpPanel->ResumeLayout(false);
			this->helpPanel->PerformLayout();
			this->p1Panel->ResumeLayout(false);
			this->p1Panel->PerformLayout();
			this->p2Panel->ResumeLayout(false);
			this->p2Panel->PerformLayout();
			this->mGameOverPanel->ResumeLayout(false);
			this->mGameOverPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//Panel Location 12,9
	private: System::Void gamemodeBtn_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		menuPanel->Enabled = false;
		menuPanel->Visible = false;
		gamemodePanel->Enabled = true;
		gamemodePanel->Visible = true;
		gamemodePanel->Location = Point(PANEL_POS, PANEL_POS);
	}
	
	private: System::Void gamemodereturnBtn_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		gamemodePanel->Enabled = false;
		gamemodePanel->Visible = false;
		menuPanel->Enabled = true;
		menuPanel->Visible = true;
	}

	private: System::Void highscoreBtn_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		menuPanel->Enabled = false;
		menuPanel->Visible = false;
		ifstream readHighScores;
		readHighScores.open("HighScores.txt");
		if (readHighScores.is_open())
		{
			int highscore;
			string initials;
			string line;
			getline(readHighScores, line);
			while (!readHighScores.fail())
			{
				readHighScores >> highscore;
				readHighScores >> initials;
				String^ score = gcnew String(initials.c_str());
				score = highscore.ToString() + " " + score;
				highScoreLabel->Text = score;
			}
			readHighScores.close();
		}
		highscorePanel->Enabled = true;
		highscorePanel->Visible = true;
		highscorePanel->Location = Point(PANEL_POS, PANEL_POS);

	}

	private: System::Void highscorereturnBtn_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		highscorePanel->Enabled = false;
		highscorePanel->Visible = false;
		menuPanel->Enabled = true;
		menuPanel->Visible = true;
	}

	private: System::Void helpBtn_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		menuPanel->Enabled = false;
		menuPanel->Visible = false;
		helpPanel->Enabled = true;
		helpPanel->Visible = true;
		helpPanel->Location = Point(PANEL_POS, PANEL_POS);
	}

	private: System::Void helpreturnBtn_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		helpPanel->Enabled = false;
		helpPanel->Visible = false;
		menuPanel->Enabled = true;
		menuPanel->Visible = true;
	}

	private: System::Void classicBtn_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		gamemodePanel->Visible = false;
		gamemodePanel->Visible = false;
		gamePanel->Location = Point(PANEL_POS, PANEL_POS);
		gamePanel->Enabled = true;
		gamePanel->Visible = true;
		mysteryLabel->Enabled = false;
		mysteryLabel->Visible = false;
		boxReward->Enabled = false;
		boxReward->Visible = false;
		direction = 'd';
		game = new SnakeGame('C', gamePanel);
		gameType = 'C';
		game->initializeGame();
		MessageBox::Show("Click Ok To Start!");
		gameTimer->Enabled = true;
		gameTimer->Start();
		this->KeyPreview = true;
	}
	private: System::Void mysteryBtn_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		gamemodePanel->Visible = false;
		gamemodePanel->Visible = false;
		gamePanel->Location = Point(PANEL_POS, PANEL_POS);
		gamePanel->Enabled = true;
		gamePanel->Visible = true;
		mysteryLabel->Enabled = true;
		mysteryLabel->Visible = true;
		boxReward->Enabled = true;
		boxReward->Visible = true;
		direction = 'd';
		game = new SnakeGame('B', gamePanel);
		gameType = 'B';
		game->initializeGame();
		MessageBox::Show("Click Ok To Start!");
		gameTimer->Enabled = true;
		gameTimer->Start();
		this->KeyPreview = true;
	}

	private: System::Void gameTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (game != nullptr && !game->isGameOver())
		{
			game->play(direction, direction2, gameTimer);
			if (gameType == 'C')
				ScoreTextBox->Text = game->getCScore().ToString();

			if (gameType == 'M')
			{
				p2Score->Text = game->getP2Score().ToString();
				p1Score->Text = game->getP1Score().ToString();
			}
			
			if (gameType == 'B')
			{
				ScoreTextBox->Text = game->getBScore().ToString();
				if (game->getBoxType() == 'M')
				{
					boxReward->Text = "Mega Fruit";
				}
				else if (game->getBoxType() == 'F')
				{
					boxReward->Text = "Speed Up";
				}
				else if (game->getBoxType() == 'S')
				{
					boxReward->Text = "Slow Down";
				}
				else if (game->getBoxType() == 'I')
				{
					boxReward->Text = "Inverse Controls";
				}
			}
		}
		else if (gameType == 'M' && game->isGameOver())
		{
			gameTimer->Stop();
			gameTimer->Enabled = false;
			p1Panel->Hide();
			p2Panel->Hide();
			mGameOverPanel->Location = Point(PANEL_POS, PANEL_POS);
			if (game->getWinningScore() == 0)
			{
				winnerLabel->Text = "";
				winningScore->Text = "";
				winnerText->Text = "Tie";
			}
			else if (game->getWinner() == 1)
			{
				winnerText->Text = "Winner";
				winningScore->Text = game->getWinningScore().ToString();
				winnerLabel->Text = "Player 1!";
			}
			else if (game->getWinner() == 2)
			{
				winnerText->Text = "Winner";
				winningScore->Text = game->getWinningScore().ToString();
				winnerLabel->Text = "Player 2!";
			}
			else
			{
				winnerLabel->Text = "";
				winningScore->Text = "";
				winnerText->Text = "Tie";
			}

			mGameOverPanel->Show();
			mGameOverPanel->Enabled = true;

		}
		else if (gameType == 'B' && game->isGameOver())
		{
			boxReward->Text = "";
			gameTimer->Stop();
			gameTimer->Enabled = false;
			MessageBox::Show("You Lost");
			gamePanel->Hide();
			menuPanel->Show();
			menuPanel->Enabled = true;
			gamemodeBtn->Enabled = true;
			highscoreBtn->Enabled = true;
			helpBtn->Enabled = true;
		}
		else
		{
			gameTimer->Stop();
			gameTimer->Enabled = false;
			game->addHighScore("Mystery");
			MessageBox::Show("You Lost");
			gamePanel->Hide();
			menuPanel->Show();
			menuPanel->Enabled = true;
			gamemodeBtn->Enabled = true;
			highscoreBtn->Enabled = true;
			helpBtn->Enabled = true;
		}
	}
	private: System::Void MyForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
	{
		if (e->KeyChar == 'w' || e->KeyChar == 'd' || e->KeyChar == 's' || e->KeyChar == 'a')
			direction = e->KeyChar;
		else
			direction2 = e->KeyChar;
	}

	private: System::Void multiBtn_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		gamemodePanel->Visible = false;
		gamemodePanel->Visible = false;
		p1Panel->Location = Point(PANEL_POS, PANEL_POS);
		p1Panel->Enabled = true;
		p1Panel->Visible = true;
		p2Panel->Location = Point((PANEL_POS + p1Panel->Width), PANEL_POS);
		p2Panel->Enabled = true;
		p2Panel->Visible = true;
		direction = 'd';
		direction2 = 'l';
		game = new SnakeGame('M', p1Panel, p2Panel);
		gameType = 'M';
		game->initializeGame();
		MessageBox::Show("Click Ok To Start!");
		gameTimer->Enabled = true;
		gameTimer->Start();
		this->KeyPreview = true;
	}

	private: System::Void toMainMenu_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
	{
		mGameOverPanel->Enabled = false;
		mGameOverPanel->Visible = false;
		menuPanel->Enabled = true;
		menuPanel->Visible = true;
	}
};
}
