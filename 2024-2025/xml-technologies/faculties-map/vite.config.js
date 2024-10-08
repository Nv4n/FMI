import * as path from 'node:path';
import { defineConfig } from "vite";
import react from '@vitejs/plugin-react';

export default defineConfig({
    build: {
        sourcemap: true,
    },
    assetsInclude: ['**/*.kml'],
    plugins: [react()],
    resolve: {
        alias: {
            '@maps': path.resolve(__dirname, './maps'),
            '@scripts': path.resolve(__dirname, './scripts'),
            '@styles': path.resolve(__dirname, './styles'),
        }
    },
});
