'use strict';
var util = require('util');
var yeoman = require('yeoman-generator');

var DriverGenerator = module.exports = function DriverGenerator(args, options, config) {
  // By calling `NamedBase` here, we get the argument to the subgenerator call
  // as `this.name`.
  yeoman.generators.NamedBase.apply(this, arguments);

  console.log('You called the driver subgenerator with the argument ' + this.name + '.');

};

util.inherits(DriverGenerator, yeoman.generators.NamedBase);


DriverGenerator.prototype.files = function files() {
    this.project_name = this.name.toLowerCase();     
    
    this.template('_char.c', this.project_name+'.c');
    this.template('_Makefile', 'Makefile');
};
