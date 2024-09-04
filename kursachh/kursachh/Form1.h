#pragma once
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <iostream>
#include <fstream>
 
int NC;
 
struct z {// ��������� ��� ������ ������ �� �����
    char name[40];// �������� �����
    char genre[20]; // ���� �����
    int price; // ���� �����
    int data; // ���� ����������
    int number; // �������
    } *knigis;
struct sp{ // ��������� ����������� �������
    char name[40];
    int number;
    struct sp* sled;
    struct sp* pred;
        }*spisok;
 
void vstavka(int number,char* name)//������� ��� ����������� ������
{
    int i;
    struct sp *nov,*nt,*z=0;
    for(nt=spisok; nt!=0 && strcmp(nt->name,name)<0; z=nt, nt=nt->sled);//����� ����� �������
    if(nt && strcmp(nt->name,name)==0) return;//�������� �� ������������� ��������
    nov=(struct sp *) malloc(sizeof(struct sp));//��������� ������ ��� �������
    strcpy(nov->name,name);//����������� �������� � ����� �������
    nov->sled=nt;//�������� ������ �� ��������� �������
    nov->pred=z;//�������� ������ �� ���������� �������
    nov->number=number;
    if(!z) spisok=nov;//�������� �� ����������� ������
    else z->sled=nov;
    if(nt) nt->pred=nov;
    return;
}
 
void text_data(char *s,char *sd)
{
int N_month;
char s0[3],month[12][9]={
"������","�������","�����","������","���","����",
"����","�������","��������","�������","������","�������"
};
strcpy(s,sd+8);
strcat(s," ");
strncpy(s0,sd+5,2);
s0[2]=0;
sscanf(s0,"%d",&N_month);
strcat(s,month[N_month-1]);
strcat(s," ");
strncat(s,sd,4);
return;
}
 
namespace kursachh {
 
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Runtime::InteropServices;
    /// <summary>
    /// ������ ��� Form1
    ///
    /// ��������! ��� ��������� ����� ����� ������ ���������� ����� ��������
    ///          �������� ����� ����� �������� ("Resource File Name") ��� �������� ���������� ������������ �������,
    ///          ���������� �� ����� ������� � ����������� .resx, �� ������� ������� ������ �����. � ��������� ������,
    ///          ������������ �� ������ ��������� �������� � ���������������
    ///          ���������, ��������������� ������ �����.
    /// </summary>
    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
            //
            //TODO: �������� ��� ������������
            //
        }
 
    protected:
        /// <summary>
        /// ���������� ��� ������������ �������.
        /// </summary>
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::MenuStrip^  menuStrip1;
    protected: 
    private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  �������ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  �����������������ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  ������������������ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  ����������������ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  ��������������������ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^  ����������������������������1990����ToolStripMenuItem;
 
    private: System::Windows::Forms::ToolStripMenuItem^  ������������������������������ToolStripMenuItem;
    private: System::Windows::Forms::TabControl^  tabControl1;
    private: System::Windows::Forms::TabPage^  tabPage1;
    private: System::Windows::Forms::TabPage^  tabPage2;
    private: System::Windows::Forms::TabPage^  tabPage3;
 
    private: System::Windows::Forms::RichTextBox^  richTextBox1;

    private: System::Windows::Forms::DataGridView^  dataGridView1;
    private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
    private: System::Windows::Forms::RichTextBox^  richTextBox2;
 
 
    private:
        /// <summary>
        /// ��������� ���������� ������������.
        /// </summary>
        System::ComponentModel::Container ^components;
 
#pragma region Windows Form Designer generated code
        /// <summary>
        /// ������������ ����� ��� ��������� ������������ - �� ���������
        /// ���������� ������� ������ ��� ������ ��������� ����.
        /// </summary>
        void InitializeComponent(void)
        {
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������������������1990����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->����ToolStripMenuItem, 
				this->�������ToolStripMenuItem, this->�����ToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(7, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(871, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->�������ToolStripMenuItem, 
				this->���������ToolStripMenuItem});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::���������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->�����������������ToolStripMenuItem, 
				this->������������������ToolStripMenuItem, this->����������������ToolStripMenuItem, this->��������������������ToolStripMenuItem, 
				this->����������������������������1990����ToolStripMenuItem, this->������������������������������ToolStripMenuItem});
			this->�������ToolStripMenuItem->Enabled = false;
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// �����������������ToolStripMenuItem
			// 
			this->�����������������ToolStripMenuItem->Name = L"�����������������ToolStripMenuItem";
			this->�����������������ToolStripMenuItem->Size = System::Drawing::Size(363, 22);
			this->�����������������ToolStripMenuItem->Text = L"����� ����� �������� ����� ������� \?";
			this->�����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����������������ToolStripMenuItem_Click);
			// 
			// ������������������ToolStripMenuItem
			// 
			this->������������������ToolStripMenuItem->Name = L"������������������ToolStripMenuItem";
			this->������������������ToolStripMenuItem->Size = System::Drawing::Size(363, 22);
			this->������������������ToolStripMenuItem->Text = L"������ ���� �� ������  �������";
			this->������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::������������������ToolStripMenuItem_Click);
			// 
			// ����������������ToolStripMenuItem
			// 
			this->����������������ToolStripMenuItem->Name = L"����������������ToolStripMenuItem";
			this->����������������ToolStripMenuItem->Size = System::Drawing::Size(363, 22);
			this->����������������ToolStripMenuItem->Text = L"����� ����� �������� ����� ������\?";
			this->����������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::����������������ToolStripMenuItem_Click);
			// 
			// ��������������������ToolStripMenuItem
			// 
			this->��������������������ToolStripMenuItem->Name = L"��������������������ToolStripMenuItem";
			this->��������������������ToolStripMenuItem->Size = System::Drawing::Size(363, 22);
			this->��������������������ToolStripMenuItem->Text = L"���������� ������ ����";
			this->��������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::��������������������ToolStripMenuItem_Click);
			// 
			// ����������������������������1990����ToolStripMenuItem
			// 
			this->����������������������������1990����ToolStripMenuItem->Name = L"����������������������������1990����ToolStripMenuItem";
			this->����������������������������1990����ToolStripMenuItem->Size = System::Drawing::Size(363, 22);
			this->����������������������������1990����ToolStripMenuItem->Text = L"����� �����, �������� � ����� ����� �� 1990 ����\?";
			this->����������������������������1990����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::����������������������������1990����ToolStripMenuItem_Click);
			// 
			// ������������������������������ToolStripMenuItem
			// 
			this->������������������������������ToolStripMenuItem->Name = L"������������������������������ToolStripMenuItem";
			this->������������������������������ToolStripMenuItem->Size = System::Drawing::Size(363, 22);
			this->������������������������������ToolStripMenuItem->Text = L"��������� ������� ���� � ���������";
			this->������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::������������������������������ToolStripMenuItem_Click);
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::�����ToolStripMenuItem_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(0, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(871, 399);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Location = System::Drawing::Point(4, 23);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(863, 372);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"�������� ������";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &Form1::tabPage1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(3, 3);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(864, 329);
			this->dataGridView1->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->richTextBox2);
			this->tabPage2->Controls->Add(this->richTextBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 23);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(863, 372);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"������";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(412, 0);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(443, 353);
			this->richTextBox2->TabIndex = 1;
			this->richTextBox2->Text = L"";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(406, 353);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 23);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(863, 372);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"���������";
			this->tabPage3->UseVisualStyleBackColor = true;
			this->tabPage3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::tabPage3_Paint);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"kursach";
			this->openFileDialog1->Filter = L"Data Files (*.dat) | *.dat";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 14);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(871, 415);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"��� �����";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
    private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
         }
private: System::Void �����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
         {
            this->Close();
         }
private: System::Void ���������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
         {
             this->Close();
         }
private: System::Void �������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
         {
FILE *in;
int i;
char ctemp[180];
String ^s;
if (openFileDialog1->ShowDialog()==System::Windows::Forms::DialogResult::OK)
{
s=openFileDialog1->FileName;
char *str_tmp=(char*)(void*)Marshal::StringToHGlobalAnsi(s);
if ((in=fopen(str_tmp,"r"))==NULL)
{ MessageBox::Show("���� �� ������!","������!",
MessageBoxButtons::OK,MessageBoxIcon::Error);
Marshal::FreeHGlobal(IntPtr((void*)str_tmp));
return;
}
Marshal::FreeHGlobal(IntPtr((void *)str_tmp));
}
else return;
/*/if ((in=fopen("kursach.dat","r"))==NULL)
{
MessageBox::Show("���� �� ������!",
"������!",
MessageBoxButtons::OK,
MessageBoxIcon::Error);
return;
}/*/
DataTable ^Table1;
Table1 = gcnew DataTable();
this->dataGridView1->DataSource = Table1;
this->dataGridView1->AllowUserToAddRows=false;
this->dataGridView1->AllowUserToDeleteRows=false;
this->dataGridView1->ReadOnly=true;
Table1->Columns->Add("�������� �����");
Table1->Columns->Add("���� �����");
Table1->Columns->Add("��� �������");
Table1->Columns->Add("����");
Table1->Columns->Add("������� ����");
 
�������ToolStripMenuItem->Enabled=true;
//listBox1->Items->Clear();
fscanf(in,"%d",&NC);
knigis = new z[NC];
 
for(i=0;i<NC;i++)
{
    fscanf(in,"%s%s%d%d%d",knigis[i].name, knigis[i].genre, &knigis[i].price, &knigis[i].data, &knigis[i].number);
/*/sprintf(ctemp,"%-35s %-20s %-10d %-10d %d",knigis[i].name, knigis[i].genre,knigis[i].price, knigis[i].data, knigis[i].number);
s=gcnew String(ctemp);
listBox1->Items->Add(s);/*/
    Table1->Rows->Add();
    s=gcnew String(knigis[i].name);
    Table1->Rows[i][0]=s; // ��� Table1->Rows[i]["���"]=s;
    s=gcnew String(knigis[i].genre);
    Table1->Rows[i][1]=s; // ��� Table1->Rows[i]["��� ������"]=s;
    Table1->Rows[i][2]=knigis[i].price; // ��� Table1->Rows[i]["�����"]=s;
    //s=gcnew String(knigis[i].data);
    Table1->Rows[i][3]=knigis[i].data; // ��� Table1->Rows[i]["����"]=s;
    Table1->Rows[i][4]=knigis[i].number;
}
 
fclose(in);
}
 
 
#pragma endregion
    private: System::Void �����������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
             {
                 
int i=0;
struct z best;
char ss[180];
String ^s;
strcpy(best.name,knigis[0].name);
best.price = knigis[0].price;
for(i=1;i<NC;i++)
        if(knigis[i].price>best.price)
        {
            strcpy(best.name,knigis[i].name);
            best.price=knigis[i].price;
        }
sprintf(ss,"\n ����� ������� %ld ������",best.price);
sprintf(ss,"����� ������� ������ �������� %s",best.name);
s=gcnew String(ss);
MessageBox::Show(s,"������� �����");
             }
 
private: System::Void ����������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
         {
int i;struct z old;
char sd[17];
char ss[80];
old.data=knigis[0].data;
String ^s;
struct z* best=knigis;
for(i=1;i<NC;i++)
  if(knigis[i].data<old.data)//�����
    {
        strcpy(old.name,knigis[i].name);
        old.data=knigis[i].data;
    }
sprintf(ss,"����� ������ ������ �������: %s ��� ��������� %d",old.name, old.data);
s=gcnew String(ss);
MessageBox::Show(s,"����� ������ �����");
         }
 
private: System::Void ������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
         {
            int i;
            char ss[180];
            String^s;
            tabControl1->SelectTab(1);
            struct z* nt;
            richTextBox1->ReadOnly=1;
            richTextBox1->Clear();
            richTextBox1->Text="\n ������ ���� �� ����� �������\n =================================";
            for(i=0,nt=knigis;i<NC;nt++,i++)
            {
                if ((strcmp(nt->genre,"�������"))==0)
                {
                sprintf(ss," %-20s  ",nt->name);
                s=gcnew String(ss,0,61);
                richTextBox1->Text=richTextBox1->Text+"\n"+s;
                }
            }
        }
private: System::Void ��������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
         {
int i;
struct sp* nt, *z=0;
char ss[180];
String ^s;
tabControl1->SelectTab(1); // ��������� �� ������� "������"
 if(!spisok)//�������� ������������� ������
        for(i=0;i<NC;i++)
            vstavka(knigis[i].number,knigis[i].name);//���������� ������� vstavka ��� ���������� ����������� ������
    richTextBox1->ReadOnly=1;
    richTextBox2->ReadOnly=1;
    richTextBox1->Clear();
    richTextBox2->Clear();
    richTextBox1->Text ="\n���������� ������\n================\n";
    for(nt=spisok; nt!=0; nt=nt->sled)
    {
        sprintf(ss,"\n %-10s ",nt->name);
        s=gcnew String(ss,0,35);
        richTextBox1->Text = richTextBox1->Text+"\n"+s;
    }
    richTextBox2->Text ="\n �������� ���������� ������\n================\n";
    for(nt=spisok; nt!=0; z=nt, nt=nt->sled);
    for(nt=z, i=0; nt!=0; i++,nt=nt->pred)
    {
        sprintf(ss,"\n %-10s ",nt->name);
        s=gcnew String(ss,0,35);
        richTextBox2->Text = richTextBox2->Text+"\n"+s;
 
    }
}
 
private: System::Void ����������������������������1990����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
    {
        int i;
            char ss[180];
            String^s;
            tabControl1->SelectTab(1);
            struct z* nt;
            richTextBox1->ReadOnly=1;
            richTextBox1->Clear();
            richTextBox1->Text="\n ����� ���������� � ����� ������������� ����� �� 1990 ����\n =================================";
            for(i=0,nt=knigis;i<NC;nt++,i++)
            {
                if (nt->data<1990 && strcmp(nt->genre,"�������������_�����")==0)
                {
                sprintf(ss," %-20s %ld ",nt->name,nt->data);
                s=gcnew String(ss,0,61);
                richTextBox1->Text=richTextBox1->Text+"\n"+s;
                }
            }
        }
 
private: System::Void ������������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
         {
             tabControl1->SelectTab(2); 
         }
 
private: System::Void tabPage3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) 
         {
Pen ^myPen= gcnew Pen(System::Drawing::Color::Black,3);
SolidBrush ^myBrush= gcnew SolidBrush(Color::FromArgb(196,0,0,0));
System::Drawing::Font^ myFont=gcnew System::Drawing::Font("Arial",8);
int i,K;
int iRed,iGreen,iBlue;
int aStart,aEnd;
float Sum;
float xPos,yPos;
struct sp *nt;
Graphics ^g=tabPage3->CreateGraphics();
g->Clear(System::Drawing::Color::White);
if(!spisok)
for(i=0;i<NC;i++)
vstavka(knigis[i].number,knigis[i].name);
K=0; Sum=0;
for(nt=spisok,i=0; nt!=0; nt=nt->sled,i++)
{
K++;
Sum+=nt->number;
}
g->DrawEllipse(myPen,25,25,185,185);
aEnd=0;
for(nt=spisok,i=0; nt!=0; nt=nt->sled,i++)
{
iRed=(((i+1)&4)>0)*255/(i/8+1);
iGreen=(((i+1)&2)>0)*255/(i/8+1);
iBlue=(((i+1)&1)>0)*255/(i/8+1);
aStart=aEnd;
aEnd+=nt->number*360/Sum;
if(i==K-1)aEnd=360;
 myBrush->Color::set(Color::FromArgb(196,iRed,iGreen,iBlue));
 g->FillPie(myBrush,25,25,185,185,aStart,aEnd-aStart);
 g->FillRectangle(myBrush,300,50+(i-1)*20,20,20);
 myBrush->Color::set(Color::FromArgb(196,0,0,0));
 xPos=30+(185-25)/2+(185-25)/1.5*Math::Cos(Math::PI*(aStart+aEnd)/360);
 yPos=30+(185-25)/2+(185-25)/1.5*Math::Sin(Math::PI*(aStart+aEnd)/360);
 g->DrawString(gcnew String(nt->name),myFont,myBrush,320,55+(i-1)*20);
 g->DrawString(Convert::ToString(nt->number),
myFont,myBrush,xPos,yPos);
 } //����� ����� for�
         }
 
private: System::Void ��������������������������ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
         {
int i,j,k=0;
char bstr[200]="";
char ss[180];
String^s;
tabControl1->SelectTab(1);
richTextBox1->Text="\n\r  �����, ���������� � ���� ���, �� � ������ ������\n\r =====================================================\n\r";
for(i=0;i<NC;i++)
    for(j=0;j<NC;j++)
        if(knigis[i].data==knigis[j].data && i!=j && strcmp(knigis[i].genre,knigis[j].genre)!=0)
        {
            if(strstr(bstr,knigis[i].name)==NULL)
            {
                sprintf(ss," %-20s %ld   %s\n",knigis[i].name,knigis[i].data, knigis[i].genre);
                s=gcnew String(ss,0,61);
                richTextBox1->Text=richTextBox1->Text+"\n"+s;
                strcat(bstr,knigis[i].name);
            }
            if(strstr(bstr,knigis[j].name)==NULL)
            {
                sprintf(ss," %-20s %ld   %s\n",knigis[j].name,knigis[j].data, knigis[j].genre);
                s=gcnew String(ss,0,61);
                richTextBox1->Text=richTextBox1->Text+"\n"+s;
                strcat(bstr,knigis[j].name);
            }
            k++;
 
        }
if(k==0) richTextBox1->Text="����� ���� ���";
         }
         
};
}