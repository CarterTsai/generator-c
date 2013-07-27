'use strict';
var util = require('util');
var path = require('path');
var yeoman = require('yeoman-generator');


var CGenerator = module.exports = function CGenerator(args, options, config) {
  yeoman.generators.Base.apply(this, arguments);

  this.on('end', function () {
    this.installDependencies({ skipInstall: options['skip-install'] });
  });

  this.pkg = JSON.parse(this.readFileAsString(path.join(__dirname, '../package.json')));
};

util.inherits(CGenerator, yeoman.generators.Base);

CGenerator.prototype.askFor = function askFor() {
  var cb = this.async();

  // have Yeoman greet the user.
  console.log(this.yeoman);

  var prompts = [{
    type: 'input',
    name: '[rojectName]',
    message: 'What is your Project Name?',
    default: 'Hello'
  }];

  this.prompt(prompts, function (props) {
    this.someOption = props.someOption;

    cb();
  }.bind(this));
};

CGenerator.prototype.app = function app() {
  this.mkdir('src');

  this.template('_main.c', 'src/main.c');
};

CGenerator.prototype.projectfiles = function projectfiles() {
  this.template('_Makefile', '.Markfile');
};
