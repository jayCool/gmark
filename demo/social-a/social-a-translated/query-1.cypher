MATCH (x0)-[:pisSubclassOf]->()<-[:plikes]-()-[:pname]->()<-[:plength]-(x1), (x1)-[:plength|plength*]->(x2), (x0)-[:pcontent]->()<-[:pname]-()-[:pname]->()<-[:pcontent]-(x3), (x2)-[:pcontent]->()<-[:pname]-()-[:pname]->()<-[:pcontent]-(x4) RETURN DISTINCT x0, x2;