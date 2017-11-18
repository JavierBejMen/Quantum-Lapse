
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
	
	
	//File
	
	void File::clear(){
		fclose(this->file);
	}
	
	File::File(const std::string& path, const std::string& mode){
		this->file = fopen(path.c_str(), mode.c_str());
	}
	
	File::~File(){
		if(this->file)
			this->clear();
	}
	
	File::operator bool() const{
		return this->file;
	}
	
	File::operator FILE*() const{
		return this->file;
	}
}
	
