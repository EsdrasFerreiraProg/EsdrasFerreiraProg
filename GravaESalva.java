package sgh;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Map;
import java.util.Vector;

public class GravaESalva {
	public void grava(Map<String, ArrayList<Paciente>> m, ArrayList<ProfissionalSaude> psaude,
			ArrayList<Paciente> pacientesNClassificados, ArrayList<Paciente> internados) {
		Vector<ArrayList> vetores = new Vector<>();
		Vector<Map> mapas = new Vector<>();
		
		vetores.add(pacientesNClassificados);
		vetores.add(psaude);
		vetores.add(internados);
		mapas.add(m);
		System.out.println(vetores.get(0));
		System.out.println(mapas);
		

		File f1 = new File("SalvaArrays.txt");
		File f2 = new File("SalvaMapa.txt");

		try {
			FileOutputStream fos1 = new FileOutputStream(f1);
			ObjectOutputStream oos1 = new ObjectOutputStream(fos1);
			FileOutputStream fos2 = new FileOutputStream(f2);
			ObjectOutputStream oos2 = new ObjectOutputStream(fos2);
			oos1.writeObject(vetores);
			oos1.close();
			oos2.writeObject(mapas);
			oos2.close();
			System.out.println("GRAVA��O CONCLU�DA COM SUCESSO!!!");

		} catch (IOException e) {

			e.printStackTrace();
		}

	}

	public Vector<Map> lerMapa() {
		File f1 = new File("SalvaMapa.txt");
		Vector<Map> d = null;

		try {
			FileInputStream fis = new FileInputStream(f1);
			ObjectInputStream ois = new ObjectInputStream(fis);
			Vector<Map> desserializar = (Vector<Map>) ois.readObject();
			System.out.println(desserializar);
			d = desserializar;
			System.out.println("mapa DESSERIALIZADO COM SUCESSO");
			ois.close();

		} catch (IOException e) {

			e.printStackTrace();
		} catch (ClassNotFoundException e) {

			e.printStackTrace();
		}

		return d;

	}

	public Vector<ArrayList> lerArray() {
		File f1 = new File("SalvaArrays.txt");
		Vector<ArrayList> d = null;

		try {
			FileInputStream fis = new FileInputStream(f1);
			ObjectInputStream ois = new ObjectInputStream(fis);
			Vector<ArrayList> desserializar = (Vector<ArrayList>) ois.readObject();
			d = desserializar;
			System.out.println("vetor DESSERIALIZADO COM SUCESSO");
			ois.close();

		} catch (IOException e) {

			e.printStackTrace();
		} catch (ClassNotFoundException e) {

			e.printStackTrace();
		}

		return d;

	}
}
