package kanalizacija;

import java.awt.Graphics;
import java.awt.Graphics2D;

public class GoreDesnoCev extends LevoDoleCev{
	
	private int x, y;

	protected void iscrtajUnutrasnjost(Graphics g) {
		x = getX();
		y = getY();
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x + getWidth() - 1, y + getHeight() - 1);
		g2.rotate(Math.PI);
		super.iscrtajUnutrasnjost(g2);
		g2.translate(x - getWidth() + 1, y - getHeight() + 1);
	}

	@Override
	protected void iscrtajIvice(Graphics g) {
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x + getWidth() - 1, y + getHeight() - 1);
		super.iscrtajIvice(g2);
		g2.translate(x - getWidth() + 1, y - getHeight() + 1);
	}
	@Override
	protected void iscrtajUsmerenjeCrta(Graphics g) {
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x + getWidth() - 1, y + getHeight() - 1);
		super.iscrtajUsmerenjeCrta(g2);
		g2.translate(x - getWidth() + 1, y - getHeight() + 1);
	}
	
	protected void iscrtajUsmerenjeStrelica(Graphics g) {
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x + getWidth() - 1, y + getHeight() - 1);
		int x = getX() + getWidth()/4;
		int y = getY() + getHeight()/2;
		g2.fillPolygon(new int[] {x,x-10,x}, new int[] {y+4, y, y-4}, 3);
		g2.translate(this.x, this.y);
	}
}
