MATCH (x0)<-[:pextendedTo]-()-[:pextendedTo]->(x1), (x1)<-[:pextendedTo]-()-[:pextendedTo]->()<-[:pextendedTo]-()<-[:pauthors]-(x2), (x2)-[:pauthors]->()<-[:pauthors]-()-[:pauthors]->()-[:pextendedTo]->(x3) RETURN DISTINCT x0, x3;