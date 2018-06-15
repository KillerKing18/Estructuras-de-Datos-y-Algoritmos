#include<iostream>

using namespace std;

class Hora {
public:
	Hora() {
		_hora = 0;
		_min = 0;
		_seg = 0;
	}

	Hora(int h, int m, int s) {
		if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59)
			throw 1;
		_hora = h;
		_min = m;
		_seg = s;
	}

	bool operator<(const Hora &h) const {
		if (_hora < h._hora)
			return true;
		else if (_hora == h._hora) {
			if (_min < h._min)
				return true;
			else if (_min == h._min) {
				if (_seg < h._seg) {
					return true;
				}
				else {
					return false;
				}
			}
			else
				return false;
		}
		else
			return false;
	}

	bool operator>(const Hora &h) const {
		if (_hora > h._hora)
			return true;
		else if (_hora == h._hora) {
			if (_min > h._min)
				return true;
			else if (_min == h._min) {
				if (_seg > h._seg) {
					return true;
				}
				else {
					return false;
				}
			}
			else
				return false;
		}
		else
			return false;
	}

	Hora & operator +(const Hora &h) const {
		int hora = 0, min = 0, seg = 0;
		seg = _seg + h._seg;
		if (seg > 59) {
			min++;
			seg = seg - 60;
		}
		min = min + _min + h._min;
		if (min > 59) {
			hora++;
			min = min - 60;
		}
		hora = hora + _hora + h._hora;
		if (hora > 23) {
			throw "OTRO DIA";
		}
		Hora suma = Hora(hora, min, seg);
		return suma;
	}

	int hora() {
		return _hora;
	}

	int min() {
		return _min;
	}

	int seg() {
		return _seg;
	}

	friend ostream &operator<< (std::ostream &out, const Hora &h) {
		out << (h._hora >= 10 ? "" : "0") << h._hora << ":"
			<< (h._min >= 10 ? "" : "0") << h._min << ":"
			<< (h._seg >= 10 ? "" : "0") << h._seg;
		return out;
	}
	friend istream &operator>> (std::istream &in, Hora &h) {
		char dos_puntos;
		int hora, min, seg;
		in >> hora;
		in >> dos_puntos;
		if (dos_puntos != ':')
			throw "ERROR";
		in >> min;
		in >> dos_puntos;
		if (dos_puntos != ':')
			throw "ERROR";
		in >> seg;
		h = Hora(hora, min, seg);
		return in;
	}

private:
	int _hora;
	int _min;
	int _seg;


};