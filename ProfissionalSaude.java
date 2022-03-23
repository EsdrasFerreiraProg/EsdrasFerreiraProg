package sgh;

import java.io.Serializable;

public class ProfissionalSaude extends Pessoa implements Serializable {
	private String[] registro = new String[2];
	

	public ProfissionalSaude() {
		super();

	}

	public ProfissionalSaude(String tipoRegistro, String numeroRegistro) {
		super();
		this.registro[0] = tipoRegistro;
		this.registro[1] = numeroRegistro;

	}

	public void setTipoRegistro(String tipo) {
		registro[0] = tipo;

	}

	public void setNumeroRegistro(String numeroRegistro) {
		registro[1] = numeroRegistro;

	}

	public String toString() {
		return "\nNome do Profissional: " + super.getNome() + "\nTipo de registro profissional : " + registro[0] + "\nNumero do registro: " + registro[1];

	}

}
