MATCH (x0)-[:p74|p54|p78*]->(x1), (x1)-[:p57]->()-[:p71]->()<-[:p69]-()<-[:p76]-(x2), (x2)-[:p35]->()<-[:p30]-()<-[:p60]-()-[:p63]->(x3) RETURN DISTINCT x0, x3;