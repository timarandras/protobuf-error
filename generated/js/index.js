const {Floats} = require('./floats_pb');

const floats = new Floats();

floats.addSamples(1.5);
floats.addSamples(2.5);
floats.addSamples(3.5);

console.log(Buffer.from(floats.serializeBinary()).toString('hex')); // 0a0c0000c03f0000204000006040

const decodeOk = Floats.deserializeBinary(Buffer.from('0a0c0000c03f0000204000006040','hex')).getSamplesList(); // [ 1.5, 2.5, 3.5 ]
const decodeFromCpp = Floats.deserializeBinary(Buffer.from('0a0c0000ffffffc03f0000204000006040','hex')); // Failure: Decoder hit an error