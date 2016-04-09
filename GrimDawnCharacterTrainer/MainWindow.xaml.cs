using GDFR;
using System.Net;
using System.Windows;

namespace GrimDawnCharacterTrainer
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private GDCFile _gdcFile;

        public MainWindow()
        {
            GDFR.GDCFile file;
            InitializeComponent();
        }
    }
}