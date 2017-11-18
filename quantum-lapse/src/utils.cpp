
#include "utils.hpp"

using namespace std;

namespace utils{
	
	//FilerErrLog
	void FileErrLog::setLog(const string& err, const string& path, const bool& good){
		this->msg = err + ". In file <"+path+">";
		this->good = good;
	}
	
	bool FileErrLog::Good() const{
		return this->good;
	}
	
	const string& FileErrLog::What() const{
		return this->msg;
	}
	
	
	
	
	
}
	
