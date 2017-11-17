
#ifndef __PIXEL_H__
#define __PIXEL_H__




/**
 * @class Pixel
 * @brief Clase que representa un pixel.
 * 
 * Entendemos por pixel la unidad mínima dentro del juego, representa
 * la casilla minima, con todos los atributos que puede tener, se utiliza
 * para representar la vista interna de los objetos o entornos en los que
 * el jugador puede estar. Además se utiliza para calcular los atributos de
 * los objetos de nivel superior i.e. Ships, Stations... mediante la clase
 * inmediatamente superior (PixelArray).
 */
class Pixel{
private:
	int weight; /**< @brief Representa el peso del pixel. */
	int structural; /**< @brief Representa la fuerza estructural del pixel. */  
	double health; /**< @brief Representa la salud del pixel. */  
	double complexity; /**< @brief Representa la complejidad del pixel. */  
	double resistance; /**< @brief Representa la resistencia del pixel. */  
	bool occupied; /**< @brief Representa si esta ocupado el pixel. */
	float posX; /**< @brief Representa la posición x en el eje cartesiano. */
	float posY; /**< @brief Representa la posición y en el eje cartesiano. */
	
	/**
	 * @brief Comprueba que todos los parámetros de entrada son correctos.
	 * 
	 * @param w Weigth >= 0.
	 * @param s Structural >= 0.
	 * @param h Health >= 0.
	 * @param c Complexity. >= 0
	 * @param o Occupied boolean.
	 * @param x posX;
	 * @param y posY;
	 */
	bool checkParam(const int& w, const int& s, const double& h, const double& c, 
		const double& r, const bool& o, const float& x, const float& y) const ;
	
	
	
	
public:
	/**
	 * @brief Constructor por defecto.
	 * 
	 * Establece todos los miembros a su valor por defecto.
	 */
	Pixel();
	
	/**
	 * @brief Constructor con parámetros.
	 * 
	 * Establece todos los miembros a los valores pasados por parámetro al constructor.
	 * @param w Weigth.
	 * @param s Structural.
	 * @param h Health.
	 * @param c Complexity.
	 * @param o Occupied.
	 * @param x posX;
	 * @param y posY;
	 */
	 Pixel(const int& w, const int& s, const double& h, const double& c, 
		const double& r, const bool& o, const float& x, const float& y);
	
	/**
	 * @brief Consultar poscición en el eje x.
	 * 
	 * @return float con la posición en el eje x.
	 */	
	float X() const;
	
	/**
	 * @brief Consultar poscición en el eje y.
	 * 
	 * @return float con la posición en el eje y.
	 */	
	float Y() const;
			
	
	
	
	
	
	
	
	
};

#endif
