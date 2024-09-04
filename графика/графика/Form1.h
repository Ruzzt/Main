#include <stdlib.h>
#include <math.h>
#pragma once

void turn(int x0, int y0, int alfa, float x, float y,float* x1, float* y1)
{
float t;
t=alfa*3.14/180;
*x1=x0+(x-x0)*cos(t)+(y-y0)*sin(t);
*y1=y0-(x-x0)*sin(t)+(y-y0)*cos(t);
return;
}

namespace графика {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:

		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::ColorDialog^  colorDialog1;


	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Courier New", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(579, 126);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(136, 117);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Draw";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(560, 355);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(580, 346);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, System::Int32::MinValue});
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(135, 20);
			this->numericUpDown2->TabIndex = 3;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {5, 0, 0, 0});
			this->numericUpDown2->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown2_ValueChanged);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox1->Location = System::Drawing::Point(579, 38);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(136, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"Rotations";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->textBox2->Location = System::Drawing::Point(580, 320);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(135, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"Speed";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(579, 12);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(136, 20);
			this->numericUpDown1->TabIndex = 2;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &Form1::numericUpDown1_ValueChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(727, 379);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
			Bitmap ^myBitmap = gcnew Bitmap(pictureBox1->Width,pictureBox1->Height);
			Graphics ^g2=Graphics::FromImage(myBitmap);
			g2->Clear(System::Drawing::Color::White);
			int xC=pictureBox1->Width/2,yC=pictureBox1->Height/2; /* середина гипотенузы */
			PointF point1=Point(xC-150,yC-75);
			PointF point2=Point(xC-150,yC-25);
			PointF point3=Point(xC-50,yC-25);			
			array <PointF> ^PointsXY={point1,point2,point3};
			Pen ^myPen= gcnew Pen(System::Drawing::Color::Black,3);
			g2->DrawPolygon(myPen,PointsXY);
			myPen->Color::set(Color::BlueViolet);
			g2->DrawEllipse(myPen,xC-4,yC-4,8,8);
			pictureBox1->BackgroundImage::set(myBitmap);
			 }
	private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void numericUpDown2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
public: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
				int N=3; // N=4 задает прямоугольник
				int xC=pictureBox1->Width/2,yC=pictureBox1->Height/2; 
				// Задаем координаты вершин треугольника
				PointF point1=Point(xC-150,yC-75);
				PointF point2=Point(xC-150,yC-25);
				PointF point3=Point(xC-50,yC-25);
				
				//Cередина 
				int i,Angle,k,Tempo; // Локальные
				float x,y,X,Y; // переменные
				// Создаем ссылку на графическую область
				Graphics ^g=pictureBox1->CreateGraphics();
				g->Clear(System::Drawing::Color::White);
				ColorDialog ^mycolor = gcnew ColorDialog();
				mycolor->AllowFullOpen = true;
				mycolor->ShowHelp = true;
				mycolor->ShowDialog();
				Pen ^myPen= gcnew Pen(mycolor->Color,3);
				// При создании пера задаем цвет(BLACK)
				// и толщину линии (3)
				array<PointF> ^PointsXY={point1,point2,point3};
				// Массив понадобится для функции
				// DrawPolygon()
				g->DrawPolygon(myPen,PointsXY);
				myPen->Color::set(Color::BlueViolet);
				g->DrawEllipse(myPen,xC-4,yC-4,8,8);
				// Число оборотов
				k=(int)this->numericUpDown1->Value;
				// Скорость вращения
				Tempo=(int)this->numericUpDown2->Value;
				// Отрицательное значение Tempo
				// означает вращение против часовой стрелки
				if(!Tempo)
				{
				MessageBox::Show("Скорость не должна равняться нулю!","Внимание!");
				return;
				}
				do{
					for(Angle=0;Angle<360;Angle+=Math::Abs(Tempo))
					 {
					
					
					for(i=0;i<N;i++)
					 {
					myPen->Color::set(Color::White);
					g->DrawPolygon(myPen,PointsXY);
					x=PointsXY[i].X; y=PointsXY[i].Y;
					turn(xC,yC,-Tempo,x,y,&X,&Y);
					PointsXY[i].X=X; PointsXY[i].Y=Y;
					myPen->Color::set(mycolor->Color);
					g->DrawPolygon(myPen,PointsXY);
					_sleep(50);
					 }
					// Черное перо рисует треугольник
					//в новом (после поворота) положении
					 //задержка на 50 мс,
					//прототип в <stdlib.h>
					}
					
				}while(--k);
					this->numericUpDown1->Value=1;
		 }
};
}

