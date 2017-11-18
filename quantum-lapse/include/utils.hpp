#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <fstream>



namespace utils{

	/**
	* @class ErrLog
	* @brief Log para tratar los fallos en las operaciones I/O.
	*/
	class FileErrLog{
	private:
		std::string msg; /**< @brief mensage de error. */
		bool good; /**< @brief True si es correcto, false si hay error */
		
	public:
		/**
		* @brief Constructor por defecto.
		*/
		FileErrLog() = default;
		
		/**
		* @brief Establece el mensaje de error y si hay error.
		*/
		void setLog(const std::string& err, const std::string& path, const bool& good);
		
		/**
		* @brief Consultar si hay error.
		* @return True si no hay, False en caso contrario.
		*/
		bool Good() const;
		
		/**
		* @brief Consultar el mensaje de error.
		* @return mensaje del error.
		*/
		const std::string& What() const;
	};
	
};





#endif
