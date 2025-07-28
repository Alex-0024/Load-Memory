#pragma once
#include <thread>

namespace LoadMemory {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoadForm
	/// </summary>
	public ref class LoadForm : public System::Windows::Forms::Form
	{
	public:
		LoadForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoadForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btStart;
	private: System::Windows::Forms::Button^ btFinish;
	private: System::Windows::Forms::NumericUpDown^ cntGB;
	private: System::Windows::Forms::TextBox^ textMessage;
	private: System::Windows::Forms::Timer^ timerChMem;
	private: System::ComponentModel::IContainer^ components;

	private:
		
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		
		System::Decimal getCntGb();
		void checkMemory();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoadForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btStart = (gcnew System::Windows::Forms::Button());
			this->btFinish = (gcnew System::Windows::Forms::Button());
			this->cntGB = (gcnew System::Windows::Forms::NumericUpDown());
			this->textMessage = (gcnew System::Windows::Forms::TextBox());
			this->timerChMem = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cntGB))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label1->Location = System::Drawing::Point(13, 12);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(474, 74);
			this->label1->TabIndex = 0;
			this->label1->Text = L"LOAD MEMORY";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(17, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(187, 33);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Size memory";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(386, 108);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(57, 33);
			this->label3->TabIndex = 2;
			this->label3->Text = L"GB";
			// 
			// btStart
			// 
			this->btStart->BackColor = System::Drawing::Color::Lime;
			this->btStart->Location = System::Drawing::Point(12, 254);
			this->btStart->Name = L"btStart";
			this->btStart->Size = System::Drawing::Size(233, 61);
			this->btStart->TabIndex = 3;
			this->btStart->Text = L"START";
			this->btStart->UseVisualStyleBackColor = false;
			this->btStart->Click += gcnew System::EventHandler(this, &LoadForm::btStart_Click);
			// 
			// btFinish
			// 
			this->btFinish->BackColor = System::Drawing::SystemColors::Control;
			this->btFinish->Cursor = System::Windows::Forms::Cursors::Default;
			this->btFinish->Enabled = false;
			this->btFinish->Location = System::Drawing::Point(255, 254);
			this->btFinish->Name = L"btFinish";
			this->btFinish->Size = System::Drawing::Size(233, 61);
			this->btFinish->TabIndex = 4;
			this->btFinish->Text = L"FINISH";
			this->btFinish->UseVisualStyleBackColor = false;
			this->btFinish->Click += gcnew System::EventHandler(this, &LoadForm::btFinish_Click);
			// 
			// cntGB
			// 
			this->cntGB->Location = System::Drawing::Point(255, 101);
			this->cntGB->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 64, 0, 0, 0 });
			this->cntGB->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->cntGB->Name = L"cntGB";
			this->cntGB->Size = System::Drawing::Size(72, 40);
			this->cntGB->TabIndex = 5;
			this->cntGB->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->cntGB->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// textMessage
			// 
			this->textMessage->Location = System::Drawing::Point(12, 180);
			this->textMessage->Name = L"textMessage";
			this->textMessage->Size = System::Drawing::Size(476, 40);
			this->textMessage->TabIndex = 6;
			// 
			// timerChMem
			// 
			this->timerChMem->Enabled = true;
			this->timerChMem->Interval = 500;
			this->timerChMem->Tick += gcnew System::EventHandler(this, &LoadForm::timerCheckMemory);
			// 
			// LoadForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(17, 33);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(500, 350);
			this->Controls->Add(this->textMessage);
			this->Controls->Add(this->cntGB);
			this->Controls->Add(this->btFinish);
			this->Controls->Add(this->btStart);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->MaximizeBox = false;
			this->Name = L"LoadForm";
			this->Text = L"Load Memory";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cntGB))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void btStart_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void btFinish_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void timerCheckMemory(System::Object^ sender, System::EventArgs^ e);
	};
};