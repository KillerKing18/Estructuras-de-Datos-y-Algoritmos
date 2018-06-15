#include"Hora.h"
#include<string>

using namespace std;

class Pelicula {
public:
	Pelicula() {
		_inicio = Hora();
		_duracion = Hora();
		_titulo = "";
	}

	Pelicula(string titulo, Hora ini, Hora duracion) {
		_inicio = ini;
		_duracion = duracion;
		_titulo = titulo;
	}

	bool operator<(const Pelicula &p) const {
		Hora h1 = _inicio + _duracion;
		Hora h2 = p._inicio + p._duracion;
		if (h1 < h2)
			return true;
		else if (h1 == h2)
			return _titulo < p._titulo;
		else
			return false;
	}

	Hora _inicio;
	Hora _duracion;
	string _titulo;
private:
};