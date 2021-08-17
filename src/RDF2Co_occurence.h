/*
 * RDF2Co_occurence.h
 *
 *  Created on: Nov 29, 2016
 *      Author: cochez, portisch
 */

#ifndef RDF2CO_OCCURENCE_H_
#define RDF2CO_OCCURENCE_H_

#include "GraphWeigher.h"
#include <string>

namespace RDF2CO {
void performExperiments(TStr filePath, GraphWeigher* weigher, std::string weigherName);
}
#endif /* RDF2CO_OCCURENCE_H_ */
