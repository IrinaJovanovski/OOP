package kanalizacija;

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.ArrayList;

public class Aplikacija extends Frame {
	
	Panel west = new Panel(new GridLayout(5, 5, 1, 1)), 
		  east = new Panel(new GridLayout(8, 1));
	
	private Kanalizacija kanalizacija = new Kanalizacija(5, 5);
	
	private Button dodaj = new Button("Dodaj");
	
	private Cev cev = null;
	
	public Aplikacija() {
		setLocation(700, 200);
		setResizable(false);
		setTitle("Cevi");
		
		populateWindow();
		
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				dispose();
			}
		});
		pack();
		setVisible(true);
	}
	
	private void populateWindow() {
		for(int i = 0; i < 5*5; i++) {
			Panel p = new Panel(new GridLayout());
			p.add(kanalizacija.kvadrati.get(i));
			west.add(p);
		}
		add(west, BorderLayout.WEST);
		CheckboxGroup smer = new CheckboxGroup();
		east.add(new Checkbox("Levo-Desno", smer, false));
		((Checkbox)east.getComponent(0)).addItemListener((ie)->{
			cev = new LevoDesnoCev();
		});
		east.add(new Checkbox("Gore-Dole", smer, false));
		((Checkbox)east.getComponent(1)).addItemListener((ie)->{
			cev = new GoreDoleCev();
		});
		east.add(new Checkbox("Dole-Gore", smer, false));
		((Checkbox)east.getComponent(2)).addItemListener((ie)->{
			cev = new DoleGoreCev();
		});
		east.add(new Checkbox("Levo-Dole", smer, false));
		((Checkbox)east.getComponent(3)).addItemListener((ie)->{
			cev = new LevoDoleCev();
		});
		east.add(new Checkbox("Levo-Gore", smer, false));
		((Checkbox)east.getComponent(4)).addItemListener((ie)->{
			cev = new LevoGoreCev();
		});
		east.add(new Checkbox("Gore-Desno", smer, false));
		((Checkbox)east.getComponent(5)).addItemListener((ie)->{
			cev = new GoreDesnoCev();
		});
		east.add(new Checkbox("Dole-Desno", smer, false));
		((Checkbox)east.getComponent(6)).addItemListener((ie)->{
			cev = new DoleDesnoCev();
		});
		east.add(dodaj);
		dodaj.addActionListener((ae)->{
			if(kanalizacija.oznacenKvadrat != null && cev != null) {
				int i = kanalizacija.dodajCev(cev);
				if(i != -1) {
					Panel p = (Panel) west.getComponent(i);
					p.removeAll();
					p.setLayout(new GridLayout());
					p.add(cev);
					p.revalidate();
					cev = null;
				}
				
			}
		});
		add(east, BorderLayout.EAST);
	}

	public static void main(String[] args) {
		new Aplikacija();
	}
}
