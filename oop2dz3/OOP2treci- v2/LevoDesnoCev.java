package kanalizacija;

import java.awt.Graphics;

public class LevoDesnoCev extends Cev {

	@Override
	protected void iscrtajUnutrasnjost(Graphics g) {
		g.fillRect(getX(), getY() + getHeight()/4, getWidth(), getHeight()/2);
	}
	
	@Override
	public void paint(Graphics g) {
		super.paint(g);
	}

	@Override
	protected void iscrtajIviceiUsmerenje(Graphics g) {
		//ivice
		g.drawLine(getX(), getY() + getHeight()/4, getX() + getWidth(), getY() + getHeight()/4);
		g.drawLine(getX(), getY() + 3*getHeight()/4, getX() + getWidth(), getY() + 3*getHeight()/4);
		//usmerenje
		g.drawLine(getX() + getWidth()/4, getY() + getHeight()/2, getX() + 3*getWidth()/4, getY() + getHeight()/2);
		int x = getX() + 3*getWidth()/4;
		int y = getY() + getHeight()/2;
		g.fillPolygon(new int[] {x,x+10,x}, new int[] {y+4, y, y-4}, 3);
	}

}
