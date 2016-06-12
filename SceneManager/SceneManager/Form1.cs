using System;
using System.IO;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SceneManager
{
    public struct Vec3
    {
        public float x, y, z;
    }

    public struct GameObject
    {
        public string name;
        public string modelPath;
        public string shaderType;
        public string lightShaderType;

        public Vec3 pos;
        public Vec3 rot;
        public Vec3 scale;
    }
    
    public partial class Form1 : Form
    {
        List<GameObject> gameObjects;
        int curIndex;
        string path = "Res/SceneInfo.dat";

        public int CurIndex
        {
            get { return gameObjectsGrid.CurrentCell.RowIndex;}
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            gameObjects = new List<GameObject>();

            ResetFormFields();

            ReadSceneInfo();
        }

        private void WriteSceneInfo()
        {
            BinaryWriter writer = new BinaryWriter(File.Open(path, FileMode.Create));

            writer.Write(gameObjects.Count);
            foreach (var gameObject in gameObjects)
            {
                writer.Write(gameObject.name);
                writer.Write(gameObject.modelPath);
                writer.Write(gameObject.shaderType);
                writer.Write(gameObject.lightShaderType);

                writer.Write(gameObject.pos.x);
                writer.Write(gameObject.pos.y);
                writer.Write(gameObject.pos.z);

                writer.Write(gameObject.rot.x);
                writer.Write(gameObject.rot.y);
                writer.Write(gameObject.rot.z);

                writer.Write(gameObject.scale.x);
                writer.Write(gameObject.scale.y);
                writer.Write(gameObject.scale.z);
            }

            writer.Close();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            bool result = (shaderTypeCombo.SelectedIndex == 1);
            lightShaderTypeCombo.Visible = result;
            label16.Visible = result;
        }

        private void ReadSceneInfo()
        {
            GameObject readedGameObject = new GameObject();

            BinaryReader reader = new BinaryReader(File.Open(path, FileMode.OpenOrCreate));

            int count = reader.ReadInt32();
            while (reader.PeekChar() != -1)
            {
                readedGameObject.name = reader.ReadString();
                readedGameObject.modelPath = reader.ReadString();
                readedGameObject.shaderType = reader.ReadString();
                readedGameObject.lightShaderType = reader.ReadString();

                readedGameObject.pos.x = reader.ReadSingle();
                readedGameObject.pos.y = reader.ReadSingle();
                readedGameObject.pos.z = reader.ReadSingle();

                readedGameObject.rot.x = reader.ReadSingle();
                readedGameObject.rot.y = reader.ReadSingle();
                readedGameObject.rot.z = reader.ReadSingle();

                readedGameObject.scale.x = reader.ReadSingle();
                readedGameObject.scale.y = reader.ReadSingle();
                readedGameObject.scale.z = reader.ReadSingle();

                gameObjects.Add(readedGameObject);
                int newRow = gameObjectsGrid.Rows.Add();
                gameObjectsGrid.Rows[newRow].Cells["ID"].Value = newRow.ToString();
                gameObjectsGrid.Rows[newRow].Cells["GOName"].Value = readedGameObject.name;
            }
            reader.Close();
            SetFormFields(gameObjects[0]);
        }

        void SetFormFields(GameObject gameObject)
        {
            nameText.Text = gameObject.name;
            modelPathText.Text = gameObject.modelPath;
            shaderTypeCombo.Text = gameObject.shaderType;
            lightShaderTypeCombo.Text = gameObject.lightShaderType;

            positionXText.Text = gameObject.pos.x.ToString();
            positionYText.Text = gameObject.pos.y.ToString();
            positionZText.Text = gameObject.pos.z.ToString();

            rotationXText.Text = gameObject.rot.x.ToString();
            rotationYText.Text = gameObject.rot.y.ToString();
            rotationZText.Text = gameObject.rot.z.ToString();

            scaleXText.Text = gameObject.scale.x.ToString();
            scaleYText.Text = gameObject.scale.y.ToString();
            scaleZText.Text = gameObject.scale.z.ToString();
        }

        void ResetFormFields()
        {
            nameText.Text = "";
            modelPathText.Text = "";
            shaderTypeCombo.Text = "StandardShader";
            lightShaderTypeCombo.Visible = false;
            lightShaderTypeCombo.Text = "Directional";

            positionXText.Text = "0";
            positionYText.Text = "0";
            positionZText.Text = "0";

            rotationXText.Text = "0";
            rotationYText.Text = "0";
            rotationZText.Text = "0";

            scaleXText.Text = "1";
            scaleYText.Text = "1";
            scaleZText.Text = "1";
        }

        private GameObject GetFormFields()
        {
            GameObject gameObject = new GameObject();

            gameObject.name = nameText.Text;
            gameObject.modelPath =  modelPathText.Text;
            gameObject.shaderType = shaderTypeCombo.Text;
            gameObject.lightShaderType = lightShaderTypeCombo.Text;

            gameObject.pos.x = Convert.ToSingle(positionXText.Text);
            gameObject.pos.y = Convert.ToSingle(positionYText.Text);
            gameObject.pos.z = Convert.ToSingle(positionZText.Text);

            gameObject.rot.x = Convert.ToSingle(rotationXText.Text);
            gameObject.rot.y = Convert.ToSingle(rotationYText.Text);
            gameObject.rot.z = Convert.ToSingle(rotationZText.Text);

            gameObject.scale.x = Convert.ToSingle(scaleXText.Text);
            gameObject.scale.y = Convert.ToSingle(scaleYText.Text);
            gameObject.scale.z = Convert.ToSingle(scaleZText.Text);

            return gameObject;
        }

        private void gameObjectsGrid_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            SetFormFields(gameObjects[CurIndex]);
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            WriteSceneInfo();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            ResetFormFields();

            GameObject newGameObject = GetFormFields();
            gameObjects.Add(newGameObject);

            int newIndex = gameObjectsGrid.Rows.Add();
            gameObjectsGrid.Rows[curIndex].Selected = false;
            gameObjectsGrid.Rows[newIndex].Selected = true;
            gameObjectsGrid.Rows[newIndex].Cells["ID"].Value = CurIndex.ToString();
            gameObjectsGrid.Rows[newIndex].Cells["GOName"].Value = newGameObject.name;
        }

        private void gameObjectsGrid_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex == gameObjects.Count)
                return;

            SetFormFields(gameObjects[CurIndex]);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            gameObjects.RemoveAt(CurIndex);
            gameObjectsGrid.Rows.RemoveAt(CurIndex);
            if (CurIndex != 0)
            {
                SetFormFields(gameObjects[CurIndex]);
            }
            else
            {
                if(gameObjects.Count != 0)
                    SetFormFields(gameObjects[CurIndex]);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            gameObjects[CurIndex] = GetFormFields();
            gameObjectsGrid.Rows[CurIndex].Cells["ID"].Value = CurIndex.ToString();
            gameObjectsGrid.Rows[CurIndex].Cells["GOName"].Value = gameObjects[CurIndex].name;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("OpenGL_Framework.exe");
            Application.Exit();
        }
    }
}
