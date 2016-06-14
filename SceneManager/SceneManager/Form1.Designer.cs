namespace SceneManager
{
    partial class Form1
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
            this.NewButton = new System.Windows.Forms.Button();
            this.nameText = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.modelPathText = new System.Windows.Forms.TextBox();
            this.label15 = new System.Windows.Forms.Label();
            this.shaderTypeCombo = new System.Windows.Forms.ComboBox();
            this.gameObjectsGrid = new System.Windows.Forms.DataGridView();
            this.GOName = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.DeleteButton = new System.Windows.Forms.Button();
            this.ExitButton = new System.Windows.Forms.Button();
            this.RunButton = new System.Windows.Forms.Button();
            this.lightShaderTypeCombo = new System.Windows.Forms.ComboBox();
            this.label16 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.scaleZText = new System.Windows.Forms.TextBox();
            this.scaleYText = new System.Windows.Forms.TextBox();
            this.scaleXText = new System.Windows.Forms.TextBox();
            this.rotationZText = new System.Windows.Forms.TextBox();
            this.rotationYText = new System.Windows.Forms.TextBox();
            this.rotationXText = new System.Windows.Forms.TextBox();
            this.positionZText = new System.Windows.Forms.TextBox();
            this.positionYText = new System.Windows.Forms.TextBox();
            this.positionXText = new System.Windows.Forms.TextBox();
            this.gameObjectTab = new System.Windows.Forms.TabControl();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.label22 = new System.Windows.Forms.Label();
            this.label21 = new System.Windows.Forms.Label();
            this.label20 = new System.Windows.Forms.Label();
            this.label19 = new System.Windows.Forms.Label();
            this.label18 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.upPicture = new System.Windows.Forms.PictureBox();
            this.rightPicture = new System.Windows.Forms.PictureBox();
            this.frontPicture = new System.Windows.Forms.PictureBox();
            this.backPicture = new System.Windows.Forms.PictureBox();
            this.downPicture = new System.Windows.Forms.PictureBox();
            this.leftPicture = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.gameObjectsGrid)).BeginInit();
            this.gameObjectTab.SuspendLayout();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.upPicture)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.rightPicture)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.frontPicture)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.backPicture)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.downPicture)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.leftPicture)).BeginInit();
            this.SuspendLayout();
            // 
            // openFileDialog1
            // 
            this.openFileDialog1.FileName = "openFileDialog1";
            // 
            // NewButton
            // 
            this.NewButton.Location = new System.Drawing.Point(12, 277);
            this.NewButton.Name = "NewButton";
            this.NewButton.Size = new System.Drawing.Size(141, 20);
            this.NewButton.TabIndex = 1;
            this.NewButton.Text = "New";
            this.NewButton.UseVisualStyleBackColor = true;
            this.NewButton.Click += new System.EventHandler(this.button2_Click);
            // 
            // nameText
            // 
            this.nameText.Location = new System.Drawing.Point(75, 16);
            this.nameText.Name = "nameText";
            this.nameText.Size = new System.Drawing.Size(228, 20);
            this.nameText.TabIndex = 2;
            this.nameText.TextChanged += new System.EventHandler(this.nameText_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(10, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(35, 13);
            this.label1.TabIndex = 3;
            this.label1.Text = "Name";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(10, 82);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(44, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "Position";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(90, 64);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(12, 13);
            this.label3.TabIndex = 6;
            this.label3.Text = "x";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(139, 64);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(12, 13);
            this.label4.TabIndex = 8;
            this.label4.Text = "y";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(187, 64);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(12, 13);
            this.label5.TabIndex = 10;
            this.label5.Text = "z";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(187, 102);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(12, 13);
            this.label6.TabIndex = 17;
            this.label6.Text = "z";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(139, 102);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(12, 13);
            this.label7.TabIndex = 15;
            this.label7.Text = "y";
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(90, 102);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(12, 13);
            this.label8.TabIndex = 13;
            this.label8.Text = "x";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(10, 121);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(47, 13);
            this.label9.TabIndex = 12;
            this.label9.Text = "Rotation";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(187, 137);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(12, 13);
            this.label10.TabIndex = 24;
            this.label10.Text = "z";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(139, 137);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(12, 13);
            this.label11.TabIndex = 22;
            this.label11.Text = "y";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Location = new System.Drawing.Point(90, 137);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(12, 13);
            this.label12.TabIndex = 20;
            this.label12.Text = "x";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(10, 156);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(34, 13);
            this.label13.TabIndex = 19;
            this.label13.Text = "Scale";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(10, 46);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(60, 13);
            this.label14.TabIndex = 25;
            this.label14.Text = "Model path";
            // 
            // modelPathText
            // 
            this.modelPathText.Location = new System.Drawing.Point(75, 43);
            this.modelPathText.Name = "modelPathText";
            this.modelPathText.Size = new System.Drawing.Size(187, 20);
            this.modelPathText.TabIndex = 26;
            this.modelPathText.TextChanged += new System.EventHandler(this.modelPathText_TextChanged);
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(10, 185);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(64, 13);
            this.label15.TabIndex = 27;
            this.label15.Text = "Shader type";
            // 
            // shaderTypeCombo
            // 
            this.shaderTypeCombo.FormattingEnabled = true;
            this.shaderTypeCombo.Items.AddRange(new object[] {
            "StandardShader",
            "LightShader"});
            this.shaderTypeCombo.Location = new System.Drawing.Point(75, 182);
            this.shaderTypeCombo.Name = "shaderTypeCombo";
            this.shaderTypeCombo.Size = new System.Drawing.Size(139, 21);
            this.shaderTypeCombo.TabIndex = 28;
            this.shaderTypeCombo.Text = "StandardShader";
            this.shaderTypeCombo.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // gameObjectsGrid
            // 
            this.gameObjectsGrid.AllowUserToAddRows = false;
            this.gameObjectsGrid.AllowUserToDeleteRows = false;
            this.gameObjectsGrid.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gameObjectsGrid.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.GOName});
            this.gameObjectsGrid.Location = new System.Drawing.Point(12, 12);
            this.gameObjectsGrid.Name = "gameObjectsGrid";
            this.gameObjectsGrid.ReadOnly = true;
            this.gameObjectsGrid.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.gameObjectsGrid.RowHeadersVisible = false;
            this.gameObjectsGrid.Size = new System.Drawing.Size(295, 258);
            this.gameObjectsGrid.TabIndex = 31;
            this.gameObjectsGrid.CellClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.gameObjectsGrid_CellClick);
            this.gameObjectsGrid.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.gameObjectsGrid_CellContentClick);
            // 
            // GOName
            // 
            this.GOName.HeaderText = "Name";
            this.GOName.Name = "GOName";
            this.GOName.ReadOnly = true;
            this.GOName.Width = 290;
            // 
            // DeleteButton
            // 
            this.DeleteButton.Location = new System.Drawing.Point(166, 276);
            this.DeleteButton.Name = "DeleteButton";
            this.DeleteButton.Size = new System.Drawing.Size(141, 21);
            this.DeleteButton.TabIndex = 33;
            this.DeleteButton.Text = "Delete";
            this.DeleteButton.UseVisualStyleBackColor = true;
            this.DeleteButton.Click += new System.EventHandler(this.button3_Click);
            // 
            // ExitButton
            // 
            this.ExitButton.Location = new System.Drawing.Point(500, 277);
            this.ExitButton.Name = "ExitButton";
            this.ExitButton.Size = new System.Drawing.Size(143, 20);
            this.ExitButton.TabIndex = 34;
            this.ExitButton.Text = "Exit";
            this.ExitButton.UseVisualStyleBackColor = true;
            this.ExitButton.Click += new System.EventHandler(this.button4_Click);
            // 
            // RunButton
            // 
            this.RunButton.Location = new System.Drawing.Point(324, 276);
            this.RunButton.Name = "RunButton";
            this.RunButton.Size = new System.Drawing.Size(143, 21);
            this.RunButton.TabIndex = 35;
            this.RunButton.Text = "Run scene";
            this.RunButton.UseVisualStyleBackColor = true;
            this.RunButton.Click += new System.EventHandler(this.button5_Click);
            // 
            // lightShaderTypeCombo
            // 
            this.lightShaderTypeCombo.FormattingEnabled = true;
            this.lightShaderTypeCombo.Items.AddRange(new object[] {
            "Directional",
            "Point",
            "Spot"});
            this.lightShaderTypeCombo.Location = new System.Drawing.Point(74, 201);
            this.lightShaderTypeCombo.Name = "lightShaderTypeCombo";
            this.lightShaderTypeCombo.Size = new System.Drawing.Size(139, 21);
            this.lightShaderTypeCombo.TabIndex = 36;
            this.lightShaderTypeCombo.Text = "Directional";
            this.lightShaderTypeCombo.Visible = false;
            this.lightShaderTypeCombo.SelectedIndexChanged += new System.EventHandler(this.lightShaderTypeCombo_SelectedIndexChanged);
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(10, 204);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(53, 13);
            this.label16.TabIndex = 37;
            this.label16.Text = "Light type";
            this.label16.Visible = false;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(268, 43);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(35, 20);
            this.button1.TabIndex = 38;
            this.button1.Text = "Find";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // scaleZText
            // 
            this.scaleZText.Location = new System.Drawing.Point(172, 153);
            this.scaleZText.Name = "scaleZText";
            this.scaleZText.Size = new System.Drawing.Size(42, 20);
            this.scaleZText.TabIndex = 23;
            this.scaleZText.TextChanged += new System.EventHandler(this.scaleZText_TextChanged);
            // 
            // scaleYText
            // 
            this.scaleYText.Location = new System.Drawing.Point(124, 153);
            this.scaleYText.Name = "scaleYText";
            this.scaleYText.Size = new System.Drawing.Size(42, 20);
            this.scaleYText.TabIndex = 21;
            this.scaleYText.TextChanged += new System.EventHandler(this.scaleYText_TextChanged);
            // 
            // scaleXText
            // 
            this.scaleXText.Location = new System.Drawing.Point(75, 153);
            this.scaleXText.Name = "scaleXText";
            this.scaleXText.Size = new System.Drawing.Size(42, 20);
            this.scaleXText.TabIndex = 18;
            this.scaleXText.TextChanged += new System.EventHandler(this.scaleXText_TextChanged);
            // 
            // rotationZText
            // 
            this.rotationZText.Location = new System.Drawing.Point(172, 118);
            this.rotationZText.Name = "rotationZText";
            this.rotationZText.Size = new System.Drawing.Size(42, 20);
            this.rotationZText.TabIndex = 16;
            this.rotationZText.TextChanged += new System.EventHandler(this.rotationZText_TextChanged);
            // 
            // rotationYText
            // 
            this.rotationYText.Location = new System.Drawing.Point(124, 118);
            this.rotationYText.Name = "rotationYText";
            this.rotationYText.Size = new System.Drawing.Size(42, 20);
            this.rotationYText.TabIndex = 14;
            this.rotationYText.TextChanged += new System.EventHandler(this.rotationYText_TextChanged);
            // 
            // rotationXText
            // 
            this.rotationXText.Location = new System.Drawing.Point(75, 118);
            this.rotationXText.Name = "rotationXText";
            this.rotationXText.Size = new System.Drawing.Size(42, 20);
            this.rotationXText.TabIndex = 11;
            this.rotationXText.TextChanged += new System.EventHandler(this.rotationXText_TextChanged);
            // 
            // positionZText
            // 
            this.positionZText.Location = new System.Drawing.Point(172, 79);
            this.positionZText.Name = "positionZText";
            this.positionZText.Size = new System.Drawing.Size(42, 20);
            this.positionZText.TabIndex = 9;
            this.positionZText.TextChanged += new System.EventHandler(this.positionZText_TextChanged);
            // 
            // positionYText
            // 
            this.positionYText.Location = new System.Drawing.Point(124, 79);
            this.positionYText.Name = "positionYText";
            this.positionYText.Size = new System.Drawing.Size(42, 20);
            this.positionYText.TabIndex = 7;
            this.positionYText.TextChanged += new System.EventHandler(this.positionYText_TextChanged);
            // 
            // positionXText
            // 
            this.positionXText.Location = new System.Drawing.Point(75, 79);
            this.positionXText.Name = "positionXText";
            this.positionXText.Size = new System.Drawing.Size(42, 20);
            this.positionXText.TabIndex = 4;
            this.positionXText.TextChanged += new System.EventHandler(this.positionXText_TextChanged);
            // 
            // gameObjectTab
            // 
            this.gameObjectTab.Controls.Add(this.tabPage1);
            this.gameObjectTab.Controls.Add(this.tabPage2);
            this.gameObjectTab.Location = new System.Drawing.Point(324, 12);
            this.gameObjectTab.Name = "gameObjectTab";
            this.gameObjectTab.SelectedIndex = 0;
            this.gameObjectTab.Size = new System.Drawing.Size(319, 258);
            this.gameObjectTab.TabIndex = 39;
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.nameText);
            this.tabPage1.Controls.Add(this.button1);
            this.tabPage1.Controls.Add(this.label16);
            this.tabPage1.Controls.Add(this.label1);
            this.tabPage1.Controls.Add(this.lightShaderTypeCombo);
            this.tabPage1.Controls.Add(this.positionXText);
            this.tabPage1.Controls.Add(this.label2);
            this.tabPage1.Controls.Add(this.label3);
            this.tabPage1.Controls.Add(this.positionYText);
            this.tabPage1.Controls.Add(this.label4);
            this.tabPage1.Controls.Add(this.shaderTypeCombo);
            this.tabPage1.Controls.Add(this.positionZText);
            this.tabPage1.Controls.Add(this.label15);
            this.tabPage1.Controls.Add(this.label5);
            this.tabPage1.Controls.Add(this.modelPathText);
            this.tabPage1.Controls.Add(this.rotationXText);
            this.tabPage1.Controls.Add(this.label14);
            this.tabPage1.Controls.Add(this.label9);
            this.tabPage1.Controls.Add(this.label10);
            this.tabPage1.Controls.Add(this.label8);
            this.tabPage1.Controls.Add(this.scaleZText);
            this.tabPage1.Controls.Add(this.rotationYText);
            this.tabPage1.Controls.Add(this.label11);
            this.tabPage1.Controls.Add(this.label7);
            this.tabPage1.Controls.Add(this.scaleYText);
            this.tabPage1.Controls.Add(this.rotationZText);
            this.tabPage1.Controls.Add(this.label12);
            this.tabPage1.Controls.Add(this.label6);
            this.tabPage1.Controls.Add(this.label13);
            this.tabPage1.Controls.Add(this.scaleXText);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(311, 232);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "GameObjects";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.label22);
            this.tabPage2.Controls.Add(this.label21);
            this.tabPage2.Controls.Add(this.label20);
            this.tabPage2.Controls.Add(this.label19);
            this.tabPage2.Controls.Add(this.label18);
            this.tabPage2.Controls.Add(this.label17);
            this.tabPage2.Controls.Add(this.upPicture);
            this.tabPage2.Controls.Add(this.rightPicture);
            this.tabPage2.Controls.Add(this.frontPicture);
            this.tabPage2.Controls.Add(this.backPicture);
            this.tabPage2.Controls.Add(this.downPicture);
            this.tabPage2.Controls.Add(this.leftPicture);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(311, 232);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "SkyBox";
            this.tabPage2.UseVisualStyleBackColor = true;
            this.tabPage2.Click += new System.EventHandler(this.tabPage2_Click);
            // 
            // label22
            // 
            this.label22.AutoSize = true;
            this.label22.Location = new System.Drawing.Point(229, 110);
            this.label22.Name = "label22";
            this.label22.Size = new System.Drawing.Size(32, 13);
            this.label22.TabIndex = 11;
            this.label22.Text = "Right";
            // 
            // label21
            // 
            this.label21.AutoSize = true;
            this.label21.Location = new System.Drawing.Point(114, 110);
            this.label21.Name = "label21";
            this.label21.Size = new System.Drawing.Size(25, 13);
            this.label21.TabIndex = 10;
            this.label21.Text = "Left";
            // 
            // label20
            // 
            this.label20.AutoSize = true;
            this.label20.Location = new System.Drawing.Point(173, 46);
            this.label20.Name = "label20";
            this.label20.Size = new System.Drawing.Size(21, 13);
            this.label20.TabIndex = 9;
            this.label20.Text = "Up";
            // 
            // label19
            // 
            this.label19.AutoSize = true;
            this.label19.Location = new System.Drawing.Point(168, 110);
            this.label19.Name = "label19";
            this.label19.Size = new System.Drawing.Size(31, 13);
            this.label19.TabIndex = 8;
            this.label19.Text = "Front";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(166, 174);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(35, 13);
            this.label18.TabIndex = 7;
            this.label18.Text = "Down";
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(47, 110);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(32, 13);
            this.label17.TabIndex = 6;
            this.label17.Text = "Back";
            // 
            // upPicture
            // 
            this.upPicture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.upPicture.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.upPicture.Location = new System.Drawing.Point(154, 27);
            this.upPicture.Name = "upPicture";
            this.upPicture.Size = new System.Drawing.Size(60, 60);
            this.upPicture.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.upPicture.TabIndex = 5;
            this.upPicture.TabStop = false;
            this.upPicture.Click += new System.EventHandler(this.pictureBox6_Click);
            // 
            // rightPicture
            // 
            this.rightPicture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.rightPicture.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.rightPicture.Location = new System.Drawing.Point(214, 87);
            this.rightPicture.Name = "rightPicture";
            this.rightPicture.Size = new System.Drawing.Size(60, 60);
            this.rightPicture.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.rightPicture.TabIndex = 4;
            this.rightPicture.TabStop = false;
            this.rightPicture.Click += new System.EventHandler(this.pictureBox5_Click);
            // 
            // frontPicture
            // 
            this.frontPicture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.frontPicture.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.frontPicture.Location = new System.Drawing.Point(154, 87);
            this.frontPicture.Name = "frontPicture";
            this.frontPicture.Size = new System.Drawing.Size(60, 60);
            this.frontPicture.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.frontPicture.TabIndex = 3;
            this.frontPicture.TabStop = false;
            this.frontPicture.Click += new System.EventHandler(this.pictureBox4_Click);
            // 
            // backPicture
            // 
            this.backPicture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.None;
            this.backPicture.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.backPicture.Location = new System.Drawing.Point(34, 87);
            this.backPicture.Name = "backPicture";
            this.backPicture.Size = new System.Drawing.Size(60, 60);
            this.backPicture.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.backPicture.TabIndex = 2;
            this.backPicture.TabStop = false;
            this.backPicture.Click += new System.EventHandler(this.pictureBox3_Click);
            // 
            // downPicture
            // 
            this.downPicture.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.downPicture.Location = new System.Drawing.Point(154, 147);
            this.downPicture.Name = "downPicture";
            this.downPicture.Size = new System.Drawing.Size(60, 60);
            this.downPicture.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.downPicture.TabIndex = 1;
            this.downPicture.TabStop = false;
            this.downPicture.Click += new System.EventHandler(this.pictureBox2_Click);
            // 
            // leftPicture
            // 
            this.leftPicture.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.leftPicture.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.leftPicture.Location = new System.Drawing.Point(94, 87);
            this.leftPicture.Name = "leftPicture";
            this.leftPicture.Size = new System.Drawing.Size(60, 60);
            this.leftPicture.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.leftPicture.TabIndex = 0;
            this.leftPicture.TabStop = false;
            this.leftPicture.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(657, 309);
            this.Controls.Add(this.gameObjectTab);
            this.Controls.Add(this.gameObjectsGrid);
            this.Controls.Add(this.NewButton);
            this.Controls.Add(this.ExitButton);
            this.Controls.Add(this.RunButton);
            this.Controls.Add(this.DeleteButton);
            this.Name = "Form1";
            this.Text = "SceneManager";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.gameObjectsGrid)).EndInit();
            this.gameObjectTab.ResumeLayout(false);
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.upPicture)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.rightPicture)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.frontPicture)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.backPicture)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.downPicture)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.leftPicture)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.OpenFileDialog openFileDialog1;
        private System.Windows.Forms.Button NewButton;
        private System.Windows.Forms.TextBox nameText;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.TextBox modelPathText;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.ComboBox shaderTypeCombo;
        private System.Windows.Forms.DataGridView gameObjectsGrid;
        private System.Windows.Forms.Button DeleteButton;
        private System.Windows.Forms.Button ExitButton;
        private System.Windows.Forms.Button RunButton;
        private System.Windows.Forms.ComboBox lightShaderTypeCombo;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.DataGridViewTextBoxColumn GOName;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox scaleZText;
        private System.Windows.Forms.TextBox scaleYText;
        private System.Windows.Forms.TextBox scaleXText;
        private System.Windows.Forms.TextBox rotationZText;
        private System.Windows.Forms.TextBox rotationYText;
        private System.Windows.Forms.TextBox rotationXText;
        private System.Windows.Forms.TextBox positionZText;
        private System.Windows.Forms.TextBox positionYText;
        private System.Windows.Forms.TextBox positionXText;
        private System.Windows.Forms.TabControl gameObjectTab;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.PictureBox rightPicture;
        private System.Windows.Forms.PictureBox frontPicture;
        private System.Windows.Forms.PictureBox backPicture;
        private System.Windows.Forms.PictureBox downPicture;
        private System.Windows.Forms.PictureBox leftPicture;
        private System.Windows.Forms.Label label22;
        private System.Windows.Forms.Label label21;
        private System.Windows.Forms.Label label20;
        private System.Windows.Forms.Label label19;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.PictureBox upPicture;
    }
}

