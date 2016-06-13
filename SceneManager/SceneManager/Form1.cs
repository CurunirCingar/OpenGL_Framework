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
using System.Text.RegularExpressions;

namespace SceneManager
{  
    public partial class Form1 : Form
    {
        List<GameObject> gameObjects;
        string path = "Res/SceneInfo.dat";
        FileStream file;

        public int CurIndex
        {
            get { return gameObjectsGrid.CurrentCell!=null ? gameObjectsGrid.CurrentCell.RowIndex : 0; }
        }

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            gameObjects = new List<GameObject>();

            openFileDialog1.InitialDirectory = Application.StartupPath;
            ReadSceneInfo();
        }

        private void WriteSceneInfo()
        {
            file = File.Open(path, FileMode.Create, FileAccess.Write);
            BinaryWriter writer = new BinaryWriter(file);

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
            file.Close();
        }

        private void ReadSceneInfo()
        {
            GameObject readedGameObject;
            file = File.Open(path, FileMode.OpenOrCreate, FileAccess.Read);
            BinaryReader reader = new BinaryReader(file);

            reader.ReadInt32();
            while (reader.PeekChar() != -1)
            {
                readedGameObject = new GameObject();
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
                gameObjectsGrid.Rows[newRow].Cells["GOName"].Value = readedGameObject.name;
            }

            reader.Close();
            file.Close();
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            bool result = (shaderTypeCombo.SelectedIndex == 1);
            lightShaderTypeCombo.Visible = result;
            label16.Visible = result;
            gameObjects[CurIndex].shaderType = shaderTypeCombo.Text;
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
            GameObject newGameObject = new GameObject();
            gameObjects.Add(newGameObject);
            int newIndex = gameObjectsGrid.Rows.Add();
            gameObjectsGrid.Rows[newIndex].Cells["GOName"].Value = "GameObject";

            SetFormFields(newGameObject);

            
        }

        private void gameObjectsGrid_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            if (e.RowIndex == gameObjects.Count)
                return;

            SetFormFields(gameObjects[CurIndex]);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (gameObjects.Count == 0)
                return;

            gameObjects.RemoveAt(CurIndex);
            gameObjectsGrid.Rows.RemoveAt(CurIndex);
            if (CurIndex != 0)
            {
                SetFormFields(gameObjects[CurIndex]);
            }
            else
            {
                if (gameObjects.Count != 0)
                    SetFormFields(gameObjects[CurIndex]);

            }
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

        private void nameText_TextChanged(object sender, EventArgs e)
        {
            gameObjects[CurIndex].name = nameText.Text;
            gameObjectsGrid.Rows[CurIndex].Cells["GOName"].Value = gameObjects[CurIndex].name;
        }

        private void positionXText_TextChanged(object sender, EventArgs e)
        {
            gameObjects[CurIndex].pos.x =  Convert.ToSingle(positionXText.Text);
        }

        private void positionYText_TextChanged(object sender, EventArgs e)
        {
            gameObjects[CurIndex].pos.y = Convert.ToSingle(positionYText.Text);
        }

        private void positionZText_TextChanged(object sender, EventArgs e)
        {
            gameObjects[CurIndex].pos.z = Convert.ToSingle(positionZText.Text);
        }

        private void rotationXText_TextChanged(object sender, EventArgs e)
        {
            gameObjects[CurIndex].rot.x = Convert.ToSingle(rotationXText.Text);
        }

        private void rotationYText_TextChanged(object sender, EventArgs e)
        {
            gameObjects[CurIndex].rot.y = Convert.ToSingle(rotationYText.Text);
        }

        private void rotationZText_TextChanged(object sender, EventArgs e)
        {
            gameObjects[CurIndex].rot.z = Convert.ToSingle(rotationZText.Text);
        }

        private void scaleXText_TextChanged(object sender, EventArgs e)
        {
            gameObjects[CurIndex].scale.x = Convert.ToSingle(scaleXText.Text);
        }

        private void scaleYText_TextChanged(object sender, EventArgs e)
        {
            gameObjects[CurIndex].scale.y = Convert.ToSingle(scaleYText.Text);
        }

        private void scaleZText_TextChanged(object sender, EventArgs e)
        {
            gameObjects[CurIndex].scale.z = Convert.ToSingle(scaleZText.Text);
        }

        private void modelPathText_TextChanged(object sender, EventArgs e)
        {
            gameObjects[CurIndex].modelPath = modelPathText.Text;
        }

        private void lightShaderTypeCombo_SelectedIndexChanged(object sender, EventArgs e)
        {
            gameObjects[CurIndex].lightShaderType = lightShaderTypeCombo.Text;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() != DialogResult.OK) return;
            string[] splitArr = Regex.Split(openFileDialog1.FileName, "\\\\Res\\\\");
            string modelPath = splitArr[splitArr.Length-1];
            modelPath = modelPath.Replace('\\', '/');
            gameObjects[CurIndex].modelPath = modelPath;
            modelPathText.Text = modelPath;
        }
    }

    public class Vec3
    {
        public Vec3(float x, float y, float z)
        {
            this.x = x;
            this.y = y;
            this.z = z;
        }
        public float x, y, z;
    }

    public class GameObject
    {
        public GameObject()
        {
            name = "GameObject";
            modelPath = "";
            shaderType = "StandardShader";
            lightShaderType = "Directional";

            pos = new Vec3(0, 0, 0);
            rot = new Vec3(0, 0, 0);
            scale = new Vec3(1, 1, 1);
        }

        public string name;
        public string modelPath;
        public string shaderType;
        public string lightShaderType;

        public Vec3 pos;
        public Vec3 rot;
        public Vec3 scale;
    }
}
