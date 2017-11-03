import java.io.IOException;
import java.net.URISyntaxException;

import javax.swing.JFrame;
import javax.swing.UIManager;
import javax.swing.ImageIcon;

public class SplashScreenMain {

	SplashScreen screen;

	public SplashScreenMain() throws IOException, URISyntaxException {
		// initialize the splash screen
		splashScreenInit();
		for (int i = 0; i <= 2000; i++)
		{
			for (long j=0; j<20000; ++j)    //50000
			{
				String poop = " " + (j + i);
			}
			// run either of these two -- not both
			SplashScreen.progressBar.setValue(i);

		}
		splashScreenDestruct();
		//System.exit(0);

		SudokuFrame sf=new SudokuFrame();
		sf.setVisible(true);
		sf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	private void splashScreenDestruct() {
		screen.setScreenVisible(false);
	}

	private void splashScreenInit() {
		ImageIcon myImage = new ImageIcon("Images/a.png");
		screen = new SplashScreen(myImage);
		screen.setLocationRelativeTo(null);
		screen.setProgressMax(2000);
		screen.setScreenVisible(true);
	}

	public static void main(String[] args) throws IOException, URISyntaxException
	{
		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		}
		catch (Exception e) {
			e.printStackTrace();
		}
		new SplashScreenMain();
	}

}
