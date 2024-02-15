'use strict'

const test = require('node:test')
const assert = require('node:assert')

const { add } = require('./index')

test('adds two numbers', () => {
  assert.equal(add(1, 1), 2)
})
