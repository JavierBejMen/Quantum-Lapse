#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>
#include <cstdio>



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
	
	/**
	* @class File
	* @brief Wrapper para fstream, libera al programador de menejar el flujo de I/O.
	*/
	class File{
	private:
		FILE* file; /**< @brief fichero fstream */
		FileErrLog errLog; /**< @brief Log de error */
		
		/**
		* @brief Cierra el fichero.
		*/
		void clear();
		
	public:
		
		/**
		* @brief Constructor por defecto.
		*/
		File() = delete;
		
		/**
		* @brief No tiene constructor de copia.
		*/
		File(const File &) = delete;
		
		/**
		* @brief Constructor con parámetros.
		* @param path Dirección del fichero.
		* @param mode modo de apertura, se especifica igual que en fstream.
		*/
		explicit File(const std::string& path, const std::string& mode);
		
		
		/**
		* @brief Destructor.
		*/
		~File();
		
		/**
		* @brief No tiene operador de asignación.
		*/
		File &operator=(const File &) = delete;
		
		/**
		* @brief Consultar si el fichero está abierto.
		*/
		operator bool() const;
		
		/**
		* @brief Operator para devolver el tipo _IO_FILE*.
		*/
		operator FILE*() const;
		
	};

};





#endif
