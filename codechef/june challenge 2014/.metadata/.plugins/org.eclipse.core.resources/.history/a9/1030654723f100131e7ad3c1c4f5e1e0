import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;

import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.DataLine;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.SourceDataLine;
import javax.sound.sampled.TargetDataLine;
import javax.swing.JButton;
import javax.swing.JFrame;


public class AudioCapture extends JFrame implements ActionListener
{
	boolean stopCapture = false;
	ByteArrayOutputStream byteArrayOutputStream;
	AudioFormat audioFormat;
	TargetDataLine targetDataLine;
	AudioInputStream audioInputStream;
	SourceDataLine sourceDataLine;
	
	final JButton startButton = new JButton("Start");
    final JButton stopButton = new JButton("Stop");
    final JButton playButton = new JButton("Playback");
	public static void main(String[] args) 
	{
		AudioCapture audioCapture=new AudioCapture();
		audioCapture.setVisible(true);
		audioCapture.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	public AudioCapture()
	{
		setSize(400,80);
		setLocation(100,100);
		this.setLayout(new GridLayout(1,3,20,20));
		this.setResizable(false);
		
		stopButton.setEnabled(false);
		playButton.setEnabled(false);
		
		add(startButton);
		add(stopButton);
		add(playButton);
		
		
		startButton.addActionListener(this);
		stopButton.addActionListener(this);
		playButton.addActionListener(this);
		
	}
	
	public Insets getInsets()
	{
		return new Insets(40,20,10,20);
	}
	@Override
	public void actionPerformed(ActionEvent ae) 
	{
		if(ae.getSource()==startButton)
		{
			startButton.setEnabled(false);
			stopButton.setEnabled(true);
			playButton.setEnabled(false);
			
			audioFormat=new AudioFormat(8000.0F,16,1,true,false);
			DataLine.Info dataLineInfo=new DataLine.Info(TargetDataLine.class,audioFormat);
			try 
			{
				targetDataLine=(TargetDataLine)AudioSystem.getLine(dataLineInfo);
				targetDataLine.open(audioFormat);
				targetDataLine.start();
				
				new CaptureThread(this);
				
			} 
			catch (LineUnavailableException e) 
			{
				e.printStackTrace();
			}
		}
		else if(ae.getSource()==stopButton)
		{
			startButton.setEnabled(true);
			stopButton.setEnabled(false);
			playButton.setEnabled(true);
			
			stopCapture=true;
		}
		else if(ae.getSource()==playButton)
		{
			byte audioData[]=byteArrayOutputStream.toByteArray();
			InputStream byteArrayInputStream=new ByteArrayInputStream(audioData);
			AudioFormat audioFormat=new AudioFormat(8000.0F,16,1,true,false);
			audioInputStream=new AudioInputStream(byteArrayInputStream,audioFormat,audioData.length/audioFormat.getFrameSize());
			
			DataLine.Info dataLineInfo =new DataLine.Info(SourceDataLine.class,audioFormat);
			try 
			{
				sourceDataLine = (SourceDataLine)AudioSystem.getLine(dataLineInfo);
				sourceDataLine.open(audioFormat);
				sourceDataLine.start();
				
				new PlayThread(this);
				
			} 
			catch (LineUnavailableException e) 
			{
				e.printStackTrace();
			}
			
		}
	}
}
class CaptureThread implements Runnable
{
	byte tempBuffer[]=new byte[10000];
	AudioCapture audioCaptureObj;
	CaptureThread(AudioCapture audioCaptureObj)
	{
		this.audioCaptureObj=audioCaptureObj;
		Thread th=new Thread(this);
		th.start();
	}
	@Override
	public void run() {
		// TODO Auto-generated method stub

		audioCaptureObj.byteArrayOutputStream=new ByteArrayOutputStream();
		audioCaptureObj.stopCapture=false;
		while(!audioCaptureObj.stopCapture)
		{
			int count=audioCaptureObj.targetDataLine.read(tempBuffer,0,tempBuffer.length);
			if(count>0)
			{
				audioCaptureObj.byteArrayOutputStream.write(tempBuffer, 0, count);
			}
		}
		try {
			audioCaptureObj.byteArrayOutputStream.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
class PlayThread implements Runnable
{
	byte tempBuffer[] = new byte[10000];
	AudioCapture audioCaptureObj;
	public PlayThread(AudioCapture audioCaptureObj)
	{
		this.audioCaptureObj=audioCaptureObj;
		Thread th=new Thread(this);
		th.start();
	}
	@Override
	public void run() 
	{
		int count;
		try {
			while((count=audioCaptureObj.audioInputStream.read(tempBuffer,0,tempBuffer.length))!=-1)
			{
				if(count>0)
				{
					audioCaptureObj.sourceDataLine.write(tempBuffer, 0, count);
				}
			}
			audioCaptureObj.sourceDataLine.drain();
			audioCaptureObj.sourceDataLine.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}