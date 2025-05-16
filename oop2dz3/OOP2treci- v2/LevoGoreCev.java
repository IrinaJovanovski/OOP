package kanalizacija;

import java.awt.Graphics;
import java.awt.Graphics2D;

public class LevoGoreCev extends LevoDoleCev {
	
	private int x, y;

	protected void iscrtajUnutrasnjost(Graphics g) {
		x = getX();
		y = getY();
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x + getWidth() - 1, y);
		g2.rotate(Math.PI/2.0);
		super.iscrtajUnutrasnjost(g2);
		g2.translate(x - getWidth() + 1, y);
	}

	@Override
	protected void iscrtajIvice(Graphics g) {
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x + getWidth() - 1, y);
		super.iscrtajIvice(g2);
		g2.translate(x - getWidth() + 1, y);
	}
	
	@Override
	protected void iscrtajUsmerenjeCrta(Graphics g) {
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x + getWidth() - 1, y);
		super.iscrtajUsmerenjeCrta(g2);
		g2.translate(x - getWidth() + 1, y);
	}
	
	protected void iscrtajUsmerenjeStrelica(Graphics g) {
		Graphics2D g2 = (Graphics2D)g;
		g2.translate(x + getWidth() - 1, y + getHeight() - 1);
		g2.rotate(-Math.PI/2.0);
		int x = getX() + getWidth()/2;
		int y = getY() + getHeight()/4;
		g2.fillPolygon(new int[] {x-4,x,x+4}, new int[] {y, y-10, y}, 3);
		g2.translate(this.x - getWidth() + 1, this.y - getHeight() + 1);
	}
	
}
