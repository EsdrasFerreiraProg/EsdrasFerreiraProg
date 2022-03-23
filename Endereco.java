package sgh;

import java.io.Serializable;

public class Endereco implements Serializable{

	private String nCasa;
	private String rua;
	private String bairro;
	private String cidade;

	public String getnCasa() {
		return nCasa;
	}

	public void setnCasa(String nCasa) {
		this.nCasa = nCasa;
	}

	public String getRua() {
		return rua;
	}

	public void setRua(String rua) {
		this.rua = rua;
	}

	public String getBairro() {
		return bairro;
	}

	public void setBairro(String bairro) {
		this.bairro = bairro;
	}

	public String getCidade() {
		return cidade;
	}

	public void setCidade(String cidade) {
		this.cidade = cidade;
	}

	public String toString() {
		return "\nCidade: " + this.cidade + "\nRua: " + this.rua + "\nBairro: " + this.bairro + "\nNumero da Casa: "
				+ this.nCasa;

	}

}
