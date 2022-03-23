package sgh;

import javax.swing.JOptionPane;

public class Recepcao {
	public static void main(String[] s) {
		SGH sgh = new SGH();
		Pessoa pessoa = new Pessoa();
		
		while (true) {
			
			
			String itens[] = {"GRAVAR", "LER", "CADASTRA NA RECEPCAO", "CADASTRAR PROFISSIONAL",
					"ENFERMAGEM: CLASSIFICAR O RISCO", "M�DICO REGISTRA NA FICHA", "TEMPO DE ESPERA", "MOSTRA PRONTUARIO",
					"SAIR",  };

			String valor = (String) JOptionPane.showInputDialog(null, "SELECIONE O QUE QUER FAZER",
					"CADASTRO DE PACIENTES", JOptionPane.INFORMATION_MESSAGE, null, itens, itens[0]);

			if (valor.equals("CADASTRA NA RECEPCAO")) {
				sgh.adicionaPacienteRecepcionista();
			}else if (valor.equals("CADASTRAR PROFISSIONAL")) {
				sgh.adicionaProfissionalSaude();
			}else if (valor.equals("ENFERMAGEM: CLASSIFICAR O RISCO")) {
				sgh.funcaoEnfermeiro();
			}else if (valor.equals("M�DICO REGISTRA NA FICHA")) {
				sgh.chamadaDoMedico();
			}else if (valor.equals("SAIR")) {
				System.exit(0);
			}else if (valor.equals("TEMPO DE ESPERA")) {
				sgh.tempoEspera();
			}else if(valor.equals("MOSTRA PRONTUARIO")) {
				sgh.prontuario();
			}else if(valor.equals("GRAVAR")) {
				sgh.gravar();
			}else if (valor.equals("LER")) {
				sgh.ler();
				
			}
		}
	}
}




