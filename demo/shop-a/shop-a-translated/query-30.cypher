MATCH (x0)-[:pprice]->()<-[:pbookEdition]-(x1), (x0)-[:ppurchaseFor]->()-[:pauthor]->()-[:ptelephone]->()<-[:pcontentRating]-(x2), (x0)-[:pprice]->()<-[:pcontentSize]-(x3), (x0)-[:pprice]->()<-[:pcontentRating]-(x4) RETURN "true" LIMIT 1;