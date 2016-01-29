/* gMark
 * Copyright (C) 2015-2016 Guillaume Bagan <guillaume.bagan@liris.cnrs.fr>
 * Copyright (C) 2015-2016 Angela Bonifati <angela.bonifati@univ-lyon1.fr>
 * Copyright (C) 2015-2016 Radu Ciucanu <radu.ciucanu@cs.ox.ac.uk>
 * Copyright (C) 2015-2016 George Fletcher <g.h.l.fletcher@tue.nl>
 * Copyright (C) 2015-2016 Aurélien Lemay <aurelien.lemay@univ-lille3.fr>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/



#include <unistd.h>
#include <fstream>

#include "config.h"
#include "gmark.h"
#include "configparser.h"
#include "workload.h"
#include "workload2.h"

int main(int argc, char ** argv) {
    string conf_file = "../use-cases/test.xml";
    string graph_file;
    string workload_file;
    int c;
    bool selectivity = false;
    long nb_nodes = -1;
    
    while ((c = getopt(argc, argv, "c:g:w:sn:")) != -1) {
        switch(c) {
            case 'c':
                conf_file = optarg;
                break;
            case 'g':
                graph_file = optarg;
                break;
            case 'w':
                workload_file = optarg;
                break;
            case 's':
                selectivity = true;
                break;
            case 'n':
                nb_nodes = atol(optarg);
        }
    }
    
    config::config conf;
    if (nb_nodes >= 0) {
        conf.nb_nodes = nb_nodes;
    }
    else {
        conf.nb_nodes = 0;
    }
    
    configparser::parse_config(conf_file, conf);
    cout << "complete config" << endl;
    conf.complete_config();
    
    
    if(graph_file != "") {
        ofstream graph_stream;
        graph_stream.open(graph_file);
        cout << "graph generation" << endl;
        graph::ntriple_graph_writer writer(graph_stream);
        writer.build_graph(conf);
        graph_stream.close();
    }
    
    if (workload_file != "") {
        ofstream workload_stream;
        workload_stream.open(workload_file);
        workload::workload wl;
        if(selectivity) {
            workload2::generate_workload(conf, wl);
        }
        else {
            workload::generate_workload(conf, wl);
        }
        workload::write_xml(wl, workload_stream);
        workload_stream.close();
        /*
        workload2::matrix mat;
        workload2::distance_matrix_between_types(conf, mat);
        cout << mat << endl;
        workload2::graph graph;
        compute_graph_from_matrix(mat, 4, graph);
        workload2::matrix_of_paths mat2;
        number_of_paths(graph, config::selectivity::CONSTANT, 3, mat2);
        vector<workload2::triple> path;
        generate_random_path(graph, mat2, -1, 3, path);
        for (auto & triple : path) {
            cout << triple << endl;
        }
        */
    }
    
}