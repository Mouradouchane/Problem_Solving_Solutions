
/*
	// problem : https://www.hackerrank.com/challenges/prettyprint/problem
	// solution ============================================================

	double A; std::cin >> A;
	double B; std::cin >> B;
	double C; std::cin >> C;


	std::cout << std::setw(0);
	std::cout << std::showbase <<
	std::nouppercase << std::hex << (long long)A << std::endl;

	std::cout << std::dec << std::right <<
	std::setw(15) << std::setfill('_') << std::showpos <<
	std::fixed << std::setprecision(2) << B << std::endl;

	std::cout << std::noshowpos << std::uppercase << std::setprecision(9);
	std::cout << std::scientific << C << std::endl;

	// =========================================================
*/