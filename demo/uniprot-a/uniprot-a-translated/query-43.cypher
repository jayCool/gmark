MATCH (x0)<-[:pPublishedIn]-()<-[:pReference]-()<-[:pInteracts]-()-[:pEncodedOn]->(x1), (x1)<-[:pEncodedOn]-()-[:pReference]->()-[:pPublishedIn]->()<-[:pPublishedIn]-(x2), (x2)<-[:pReference]-()<-[:pInteracts]-()-[:pReference]->()-[:pPublishedIn]->(x3) RETURN DISTINCT x2, x1, x0;