///////////////////////////////////////////////
/*   any sequence of 8-bit symbols on input  */
/* return sequence of 64, 96 or 128 bytes    */
///////////////////////////////////////////////
#include <iostream>
#include <string>
#include <stdlib.h>
#include "hashfunctions.h"

int main(int argc, char* argv[])
{
	//const std::string key = "abcdefghijklmnopqrstuvwxyz1234567890";
	const std::string key = "12341";
	std::cout << "General Purpose Hash Function Algorithms Test" << std::endl;
	std::cout << "Key: " << key << std::endl;
	std::cout << " 1. RS-Hash Function Value:   " << std::hex << RSHash(key)  << std::endl;
	std::cout << " 2. JS-Hash Function Value:   " << std::hex << JSHash(key)  << std::endl;
	std::cout << " 3. PJW-Hash Function Value:  " << std::hex << PJWHash(key) << std::endl;
	std::cout << " 4. ELF-Hash Function Value:  " << std::hex << ELFHash(key) << std::endl;
	std::cout << " 5. BKDR-Hash Function Value: " << std::hex << BKDRHash(key) << std::endl;
	std::cout << " 6. SDBM-Hash Function Value: " << std::hex << SDBMHash(key) << std::endl;
	std::cout << " 7. DJB-Hash Function Value:  " << std::hex << DJBHash(key) << std::endl;
	std::cout << " 8. DEK-Hash Function Value:  " << std::hex << DEKHash(key) << std::endl;
	std::cout << " 9. FNV-Hash Function Value:  " << std::hex << FNVHash(key) << std::endl;
	std::cout << "10. BP-Hash Function Value:   " << std::hex << BPHash(key) << std::endl;
	std::cout << "11. AP-Hash Function Value:   " << std::hex << APHash(key) << std::endl;
	system("PAUSE");
	return 0;
	
}