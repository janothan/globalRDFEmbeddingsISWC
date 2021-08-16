/*
 * Main.cpp
 *
 *  Created on: Nov 29, 2016
 *      Author: cochez
 */

#include "Snap.h"

#include "RandomWalkExperiments.h"

#include "RDF2Co_occurence.h"

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool containsCheckword(const char *checkword, int argc, char **argv) {
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], checkword) == 0) {
			return true;
		}
	}
	return false;
}

string containsCheckwordStr(const char *checkword, int argc, char **argv) {
	return containsCheckword(checkword, argc, argv) ? "true" : "false";
}

string getSucceedingParameter(const char *checkWord, int argc, char **argv) {
	if (!containsCheckword(checkWord, argc, argv)) {
		return "";
	}
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], checkWord) == 0 && i + 1 < argc) {
			return argv[i + 1];
		}
	}
	return "";
}

int main(int argc, char **argv) {
	TStr filePath = TStr("graph.nt");
	const char *graphParameter = "graph";
	string filePathStr = getSucceedingParameter(graphParameter, argc, argv);
	if (filePathStr.compare("") != 0) {
		filePath = TStr(filePathStr.c_str());
	} else {
		cout << "No 'graph' parameter found. Using default graph file.\n";
	}
	cout << "Using graph file: '" << filePath.CStr() << "'\n";

	vector<GraphWeigher*> weighers;
	// those are the working ones...
	weighers.push_back(new UniformWeigher);
	weighers.push_back(new PredicateFrequencyWeigher);
	weighers.push_back(new InversePredicateFrequencyWeigher);
	weighers.push_back(new ObjectFrequencyWeigher);
	weighers.push_back(new InverseObjectFrequencyWeigher);
	weighers.push_back(new InverseObjectFrequencyWeigherSplitDown);
	weighers.push_back(new PredicateObjectFrequencyWeigher);
	weighers.push_back(new InversePredicateObjectFrequencyWeigher);
	string weigherNames[8] = { "Unif", "Pred", "InvPred", "Obj", "InvObj",
			"InvObjSD", "PredObj", "InvPredObj" };

	// using default: first weigher
	int option;
	const char *optionParameter = "mode";
	string graphWeigherStr = getSucceedingParameter(optionParameter, argc,
			argv);
	if (graphWeigherStr.compare("") != 0) {
		option = stoi(graphWeigherStr);
	} else {
		cout << "No 'mode' parameter found. Using default mode 0.\n";
		option = 0;
	}
	GraphWeigher *weigher = weighers[option];

	cout << "Using mode: " << option << "\n";

	try {
		RDF2CO::performExperiments(filePath, weigher);
	} catch (char const *str) {
		cout << str << endl;
		throw str;
	}
	return 0;
}

int mainRandomWalk(int argc, char **argv) {

//RandomWalkExperiments::performExperiments(1);

//return 0;

	if (argc < 2) {
		cerr << "Usage: commandName [number], where number from" << endl;
		cerr << "	1. Uniform" << endl << "	2. Predicate freq" << endl
				<< "	3. Predicate inv. freq" << endl << "	4. Object freq"
				<< endl << "	5. Object inv. freq" << endl << "	6. P-O freq"
				<< endl << "	7. P-O inv. freq" << endl << "	8. Pagerank weight"
				<< endl << "	9. inv Pagerank weight" << endl
				<< "	10. Pagerank split weight" << endl
				<< "	11. inv Pagerank split weight" << endl
				<< "	12. Object inv. freq split" << endl
				<< "	Object freq split == uniform" << endl;
		return 1;
	}

	TStr strategy(argv[1]);
	int strategyNumber = strategy.GetInt();

	char *outFileName = NULL;
	if (argc > 2) {
		outFileName = argv[2];
	}

	RandomWalkExperiments::performExperiments(strategyNumber, outFileName);

//RDF2CO::performExperiments();
	return 0;
}

