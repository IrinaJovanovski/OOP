package kanalizacija;

import java.awt.*;
import java.awt.event.*;

public class Kvadrat extends Canvas{
	
	private boolean oznacen = false;
	
	private int sirina = 75, visina = 75;
	
	private Color pozadina;
	
	public Kvadrat(Color c) {
		pozadina = c;
		setSize(new Dimension(sirina, visina));
		setBackground(pozadina);
	}
	
	@Override
	public void paint(Graphics g) {
		if(oznacen) {
			g.setColor(Color.RED);
			g.drawRect(getX() + 1, getY() + 1, sirina - 2, visina - 2);
		}
	}
	
	public boolean mozeOznaka() {
		return true;
	}
	
	public void postaviOznaku(boolean o) throws GOznaka {
		if(o && !mozeOznaka()) throw new GOznaka();
		oznacen = o;
		repaint();
	}
	
	
}
