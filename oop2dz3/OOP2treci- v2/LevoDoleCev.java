package kanalizacija;

import java.awt.Graphics;

public class LevoDoleCev extends Cev{

	@Override
	protected void iscrtajUnutrasnjost(Graphics g) {
		g.fillRect(getX(), getY() + getHeight()/4, 3*getWidth()/4, getHeight()/2);
		g.fillRect(getX() + getWidth()/4, getY() + getHeight()/4, getWidth()/2 + 1, 3*getHeight()/4);
	}

	@Override
	protected void iscrtajIviceiUsmerenje(Graphics g) {
		//ivice
		iscrtajIvice(g);
		//usmerenje
		iscrtajUsmerenje(g);
	}
	
	protected void iscrtajIvice(Graphics g) {
		g.drawLine(getX() + 1, getY() + getHeight()/4, getX() + 3*getWidth()/4 + 1, getY() + getHeight()/4);
		g.drawLine(getX() + 1, getY() + 3*getHeight()/4, getX() + getWidth()/4 + 1, getY() + 3*getHeight()/4);
		
		g.drawLine(getX() + getWidth()/4, getY() + 3*getHeight()/4, getX() + getWidth()/4, getY() + getHeight());
		g.drawLine(getX() + 3*getWidth()/4, getY() + getHeight()/4, getX() + 3*getWidth()/4, getY() + getHeight());
	}
	
	protected void iscrtajUsmerenje(Graphics g){
		iscrtajUsmerenjeCrta(g);
		iscrtajUsmerenjeStrelica(g);
	}
	
	protected void iscrtajUsmerenjeCrta(Graphics g) {
		g.drawLine(getX() + getWidth()/4, getY() + getHeight()/2, getX() + getWidth()/2, getY() + getHeight()/2);
		g.drawLine(getX() + getWidth()/2, getY() + getHeight()/2, getX() + getWidth()/2, getY() + 3*getHeight()/4);
	}
	
	protected void iscrtajUsmerenjeStrelica(Graphics g) {
		int x = getX() + getWidth()/2;
		int y = getY() + 3*getHeight()/4;
		g.fillPolygon(new int[] {x-4,x,x+4}, new int[] {y, y+10, y}, 3);
	}
}
