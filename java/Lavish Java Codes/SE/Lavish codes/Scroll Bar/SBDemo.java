import java.awt.*;
import java.awt.event.*;
import java.applet.*;

/*
	<applet code="SBDemo" width=500 height=500>
	</applet>
*/

public class SBDemo extends Applet implements AdjustmentListener
{
	Panel p;
	Panel pShow;
	Scrollbar sbr,sbg,sbb;
	public void init()
	{
		setBackground(new Color(150,150,150));
		
		sbr=new Scrollbar(Scrollbar.VERTICAL,255,10,0,265);
		sbg=new Scrollbar(Scrollbar.VERTICAL,255,10,0,265);
		sbb=new Scrollbar(Scrollbar.VERTICAL,255,10,0,265);
		
		setLayout(new BorderLayout(20,10));
		
		p=new Panel();
		p.setLayout(new GridLayout(1,3,5,5));
		
		p.add(sbr);
		p.add(sbg);
		p.add(sbb);
		pShow=new Panel();
		pShow.setBackground(new Color(255,255,255));
		
		add(p,BorderLayout.WEST);
		add(pShow,BorderLayout.CENTER);
		
		sbr.setUnitIncrement(1);
		sbg.setUnitIncrement(1);
		sbb.setUnitIncrement(1);
		
		sbr.setBlockIncrement(10);
		sbg.setBlockIncrement(10);
		sbb.setBlockIncrement(10);
		
		
		sbr.addAdjustmentListener(this);
		sbg.addAdjustmentListener(this);
		sbb.addAdjustmentListener(this);
		
	}
	public void paint(Graphics g)
	{
	}
	public void start()
	{
	}
	public Insets getInsets()
	{
		return new Insets(20,20,10,10);
	}
	public void adjustmentValueChanged(AdjustmentEvent e)
	{
		pShow.setBackground(new Color(255-sbr.getValue(),255-sbg.getValue(),255-sbb.getValue()));
		this.showStatus("Red : "+(255-sbr.getValue())+"     Green : "+(255-sbg.getValue())+"      Blue : "+(255-sbb.getValue()));
	}
}